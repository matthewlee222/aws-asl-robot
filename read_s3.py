import boto3
import json
from boto3 import client
import webbrowser
import time
import serial
import serial.tools.list_ports


arduino = serial.Serial(port='/dev/cu.usbmodem11302', baudrate=9600, timeout=.1)
BUCKET = 'transcribeoutputtext'
FILE_TO_READ = 'transcribe.json'
client = client('s3',
                        aws_access_key_id= AWS_ACCESS_KEY_ID,
                        aws_secret_access_key=AWS_SECRET_ACCESS_KEY
                        )
s3 = boto3.resource('s3',
                        aws_access_key_id= AWS_ACCESS_KEY_ID,
                        aws_secret_access_key=AWS_SECRET_ACCESS_KEY
                        )
bucket = s3.Bucket(BUCKET)

while True:

    # Check if file exists in bucked
    objs = list(bucket.objects.filter(Prefix=FILE_TO_READ))

    
    if len(objs) == 1 and objs[0].key == FILE_TO_READ:

        result = client.get_object(Bucket=BUCKET, Key=FILE_TO_READ) 
        text = result["Body"].read().decode()
        json_content = json.loads(text)
        return_string = json_content["results"]["transcripts"][0]["transcript"]

        for s in return_string:
            if s.isalpha():
                s = s.capitalize()
                arduino.write(bytes(s, 'utf-8'))
                time.sleep(2)

        client.delete_object(Bucket=BUCKET, Key=FILE_TO_READ)
