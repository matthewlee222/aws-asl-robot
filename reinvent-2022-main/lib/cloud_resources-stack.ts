import * as cdk from 'aws-cdk-lib';
import * as lambda from 'aws-cdk-lib/aws-lambda';
import * as lex from 'aws-cdk-lib/aws-lex';
import * as s3 from 'aws-cdk-lib/aws-s3';
import * as events from 'aws-cdk-lib/aws-lambda-event-sources';
import * as path from 'path';
import { Construct } from 'constructs';
import * as iam from 'aws-cdk-lib/aws-iam';
// import * as sqs from 'aws-cdk-lib/aws-sqs';

/*TO DO

LexBot:
-add language
-add intent
-add output to S3

Lambda:
-add trigger from S3
 */

export class CloudResourcesStack extends cdk.Stack {
  constructor(scope: Construct, id: string, props?: cdk.StackProps) {
    super(scope, id, props);

    // The code that defines your stack goes here

    // example resource
    // const queue = new sqs.Queue(this, 'CloudResourcesQueue', {
    //   visibilityTimeout: cdk.Duration.seconds(300)
    // });

    const dataPrivacy: lex.CfnBot.DataPrivacyProperty={
      childDirected: false,
    };
    

    const lexRole = new iam.Role(this, 'lexRole', {
      assumedBy: new iam.ServicePrincipal('lex.amazonaws.com'),
      inlinePolicies: {
        ['lexPolicy']: new iam.PolicyDocument({
          statements: [
            new iam.PolicyStatement({
              resources: ['*'],
              actions: ['polly:SynthesizeSpeech', 'comprehend:DetectSentiment'],
            }),
          ],
        }),
      },
    });

    //const sentimentAnalysisSettings: any;
    const botId = 'InputTextBot';

    const lexOutputBucket = new s3.Bucket(this, 'lexOutputBucket');

    const transcribeOutputBucket = new s3.Bucket(this, 'transcribeoutputtext');

    const audioLogSettings: lex.CfnBot.AudioLogSettingProperty={
      destination: {
        s3Bucket: {
          logPrefix: 'logPrefix',
          s3BucketArn: lexOutputBucket.bucketArn
        },
      },
      enabled: false,
    };

    const inputBot = new lex.CfnBot(this,botId,{
      dataPrivacy: dataPrivacy,
      idleSessionTtlInSeconds: 123,
      name: 'name',
      roleArn: lexRole.roleArn
    });
    
    const botAlias = new lex.CfnBotAlias(this,'botAlias',{
      botAliasName:"InputBotAlias",
      botId:inputBot.attrId,
      conversationLogSettings: {
        audioLogSettings: [{
          destination: {
            s3Bucket: {
              logPrefix: 'logPrefix',
              s3BucketArn: lexOutputBucket.bucketArn,
            },
          },
          enabled: true,
        }]
      }
    })


    const lexToTranscribe = new lambda.Function(this, 'MyFunction', {
      runtime: lambda.Runtime.PYTHON_3_8,
      handler: 'lambda-transcribe.lambda_handler',
      code: lambda.Code.fromAsset(path.join(__dirname, '../lambdas')),
    });


    const s3PutEventSource = new events.S3EventSource(lexOutputBucket, {
      events: [
        s3.EventType.OBJECT_CREATED_PUT
      ]
    });

    
  }
}