import json
import urllib.parse
import boto3

#Gets Data from Transcribe Output S3 for Arduino function

s3 = boto3.resource('s3')


def lambda_handler(event, context):
    # Get the object from the event
    bucket = event['Records'][0]['s3']['bucket']['name']
    key = urllib.parse.unquote_plus(event['Records'][0]['s3']['object']['key'], encoding='utf-8')
    content_object = s3.Object(bucket, key)
    file_content = content_object.get()['Body'].read().decode('utf-8')
    json_content = json.loads(file_content)
    return_string = json_content["results"]["transcripts"][0]["transcript"]

    return {
        'statusCode': 200,
        'body': return_string
    }
