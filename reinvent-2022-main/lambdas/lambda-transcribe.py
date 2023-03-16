import boto3
import uuid
import json


def lambda_handler(event, context):
    client = boto3.client('transcribe')
    
    client.delete_transcription_job(
            TranscriptionJobName='transcribe')


    record = event['Records'][0]
    
    s3bucket = record['s3']['bucket']['name']
    s3object = record['s3']['object']['key']
    #s3file = s3object.substr(s3object.lastIndexOf("/")+1)
    
    s3Path = "https://s3.us-east-1.amazonaws.com/" + s3bucket + "/" + s3object
    jobName = 'transcribe' #str(uuid.uuid4()) #s3file + '-' + str(uuid.uuid4())

    

    response = client.start_transcription_job(
        TranscriptionJobName=jobName,
        LanguageCode='en-US',
        MediaFormat='wav',
        Media={
            'MediaFileUri': s3Path
        },
        OutputBucketName = "transcribeoutputtext"
    )
    

    # 

    return {
        'TranscriptionJobName': response['TranscriptionJob']['TranscriptionJobName']
    }