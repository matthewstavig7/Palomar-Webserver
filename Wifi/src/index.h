/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-web-server-multiple-pages
 */

const char *HTML_CONTENT_HOME = R""""(
<!DOCTYPE html>
<html> <!lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <link rel="icon" href="data:,">
    <title>Home Page</title>
</head>
<body>
    <h1>Welcome to the Patient monitor Home Page</h1>
    <ul>
        <li><a href="/subject1">Suject1 Page</a></li>
        <!--
        <li><a href="/spo2">SpO2 Page</a></li>
        <li><a href="/blood_pressure"> Page</a></li>
        -->

    </ul>
</body>
</html>
)"""";
