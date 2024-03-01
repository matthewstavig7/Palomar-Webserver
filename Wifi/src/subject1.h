/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-web-server-multiple-pages
 */

const char *HTML_CONTENT_SUBJECT1 = R""""(
<!-- Used Chat GPT create website-->
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Patient Vital Monitoring</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f4f4f4;
        }

        header {
            background-color: #4D4D4D;
            color: #fff;
            padding: 10px;
            text-align: center;
        }

        .img-wsu {
            width: 8%;
            height: 12%;
            position: absolute;
            top: 10px;
            left: 16px;
        } 

        
        main {
            padding: 20px;
        }

        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 20px;
        }

        th, td {
            border: 1px solid #ddd;
            padding: 12px;
            text-align: left;
        }

        th {
            background-color: #A60F2D;
            color: white;
        }

        tr:hover {
            background-color: #f5f5f5;
        }

        footer {
            background-color: #4D4D4D;
            color: #fff;
            padding: 10px;
            text-align: center;
            position: fixed;
            bottom: 0;
            width: 100%;
        }
    </style>
</head>
<body>
    <header>
        <h1>Palomar Patient Vital Monitoring</h1>
        <img src ="images/WSU.png" class="img-wsu">
    </header>

    <main>
        <h2>Patient Information</h2>
        <table>
            <tr>
                <th>Patient ID</th>
                <th>Name</th>
                <th>Age</th>
                <th>Sex</th>
            </tr>
            <tr>
                <td>001</td>
                <td>Sinclair Longbottom</td>
                <td>35</td>
                <td>Male/Female</td>
            </tr>
            <!-- Add more patient data rows as needed -->
        </table>

        <h2>Vital Signs</h2>
        <table>
            <tr>
                <th>Timestamp</th>
                <th>Blood Pressure (mmHg)</th>
                <th>Heart Rate (bpm)</th>                
                <th>SpO2 (%)</th>
            </tr>
            <tr>
                <td>2024-02-29 08:00:00</td>
                <td>120/80</td>
                <td>75</td>                
                <td>98</td>
            </tr>
            <!-- Add more vital signs data rows as needed -->
        </table>
    </main>

    <footer>
        <p>&copy; 2024 Team Palomar</p>
    </footer>
</body>
</html>)"""";
