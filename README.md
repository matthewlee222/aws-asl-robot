# ASL Translator Robotic Hand with AWS

On November 30 and December 1, 2022, our team—comprising two Professional Services Consultants and an Associate Solutions Architect—presented an American Sign Language (ASL) Translator at the AWS re:Invent 2022 Conference. Built using AWS services, the ASL Translator leverages technologies such as voice-to-text and serverless compute to deliver a seamless user experience. It captures spoken input through a microphone and translates it into ASL in real time. A robotic hand then finger-spells the translated words or phrases, helping users—especially beginners—learn how to sign.

With a simple robotic hand and an intuitive AWS-powered interface, users can now visualize ASL finger and hand motions. Those new to ASL can use the translator as an entry point to learn the language and better communicate with the hard-of-hearing community. Meanwhile, experienced users can mimic the robotic hand to practice and refine their fluency.

The user speaks into a microphone via the Amazon Lex chatbot interface. The recorded audio is saved to an Amazon S3 bucket, which triggers an AWS Lambda function to invoke Amazon Transcribe and convert the audio into text. This text is stored in another S3 bucket. A Python script monitors the bucket, retrieves the text, and sends it to an Arduino, which runs code to control the robotic hand. The Arduino triggers specific hand movements based on the received text, enabling accurate ASL finger-spelling.

![AWS Diagram](https://github.com/matthewlee222/reinvent-bot-2022/assets/58535185/0b3f0c1a-0616-454b-a9e8-ab7a94229163)
