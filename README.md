# ASL Translator Robotic Hand with AWS

On November 30 and December 1st 2022, our team of two Professional Services Consultants and an Associate Solutions Architect 
presented an American Sign Language (ASL) translator that uses AWS services at the AWS re:Invent 2022 Conference.
The ASL Translator harnesses the power of AWS cloud, utilizing technologies including voice-to-text and serverless compute,
to deliver a seamless user experience. The ASL Translator uses a microphone to intake user speech and translates the audio
into ASL in real-time. The robotic hand has been programmed to finger spell any word or phrase a user provides in order to
teach novices how to sign.

Customers will now be able to visualize the hand and finger motions of ASL with a simple
robotic hand connected to an easy-to-use AWS interface. Users who were not familiar with ASL before can now learn the
language to better communicate with the hard-of-hearing community . Additionally , those who are already familiar with ASL can
improve and mimic the robotic hand to practice their fluency in the language.

A user will speak into a microphone while recording via the Amazon Lex chat box interface.
The audio input will be saved as a file to an S3 bucket and will trigger an Amazon Lambda function to run the Amazon
Transcribe API to convert the audio into text, which gets saved to a new S3 bucket. The Python script has connectivity to this
S3 bucket and triggers the Arduino code while passing the text from the S3 bucket to the Arduino. The Arduino code controls
the hands movement and the appropriate function gets triggered to move the hand based on the passed in text.

![AWS Diagram](https://github.com/matthewlee222/reinvent-bot-2022/assets/58535185/0b3f0c1a-0616-454b-a9e8-ab7a94229163)
