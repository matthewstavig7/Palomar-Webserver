// Load Wi-Fi library
#include <WiFi.h>
#include <WebServer.h>

#include "index.h"
#include "subject1.h"
#include "spo2.h"
#include "blood_pressure.h"
#include "error_404.h"
#include "error_405.h"

//define pages
#define INDEX_PAGE 0
#define SUBJECT1_PAGE 1
#define SPO2_PAGE 2
#define BP_PAGE 3

//define error pages
#define ERROR_404_PAGE -1
#define ERROR_405_PAGE -2

// Replace with your network credentials
const char* ssid = "LAPTOP-OSBR9R3C 2190";
const char* password = "*69048uB";

// Set web server port number to 80
WiFiServer server(80);


// Setup code from Random Nerd Tutorials
void setup() {
  //initialize serial
  Serial.begin(115200);
  
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    // wait for connection
    delay(500);
    Serial.print(".");
  }

  // Print local IP address and start web server
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}


void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    
    //Serial.println("New Client.");          // print a message out in the serial port
    //String currentLine = "";                
    // read first line of HTTP request header
    String HTTP_request = "";
    
    while (client.connected()) {
      if (client.available()) {
        Serial.println("New HTTP Request");
        HTTP_request = client.readStringUntil('\n'); // read first line of HTTP request
        Serial.print("<< ");
        Serial.println(HTTP_request); // print HTTP request to the serial monitor
        break;
      }
    }

    // read reamaing lines of HTTP request header
    while (client.connected()) {
      if (client.available()) {             // if there's bytes to read from the client,
      String Header = client.readStringUntil('\n'); // read the header line of HTTP request

      if (Header.equals("\r")) // end HTTP request
      break;

      Serial.print("<< ");
      Serial.println(Header); // print HTTP request to monitor
      }
    }
    // ROUTING
    // This example supports the following:
    // - GET /
    // - GET /index
    // - GET /index.html
    // - GET /temperature
    // - GET /temperature.html
    // - GET /door
    // - GET /door.html
    // - GET /led
    // - GET /led.html

    int page_id = 0;

    if (HTTP_request.indexOf("GET") == 0) {
      if (HTTP_request.indexOf("GET / ") > -1 || HTTP_request.indexOf("GET /index ") > -1 || HTTP_request.indexOf("GET /index.html ") > -1){
        Serial.println("Home Page!");
        page_id = INDEX_PAGE;
      }
      else if (HTTP_request.indexOf("GET /subject1 ") > -1 || HTTP_request.indexOf("GET /subject1.html ") > -1){
        Serial.println("Subject1 Page!");
        page_id = SUBJECT1_PAGE;
      }
      else if (HTTP_request.indexOf("GET /spo2 ") > -1 || HTTP_request.indexOf("GET /spo2.html ") > -1){
        Serial.println("SpO2 Page!");
        page_id = SPO2_PAGE;
      }
      else if (HTTP_request.indexOf("GET /blood_pressure ") > -1 || HTTP_request.indexOf("GET /blood_pressure.html ") > -1){
        Serial.println("Blood Pressure Page!");
        page_id = BP_PAGE;
      }
      else { //Page not found
        Serial.println("Page Not Found (Error 404)");
        page_id = ERROR_404_PAGE;
      }
    }
    else { // Method Not Allowed
      Serial.println("Method Not Allowed (Error 405)");
      page_id = ERROR_405_PAGE;
    }
    
    // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
    // and a content-type so the client knows what's coming, then a blank line:
    if (page_id == ERROR_404_PAGE)
      client.println("HTTP/1.1 404 Error Page Not Found");
    if(page_id == ERROR_405_PAGE)
      client.println("HTTP/1.1 Error 405 Method Not Allowed");
    else
      // connected to webpage
      client.println("HTTP/1.1 200 OK");
    
    client.println("Content-type:text/html");
    client.println("Connection: close");
    client.println();    

/*
    // send the simple HTTP response body copied from Arduino Get Started
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head>");
    client.println("<link rel=\"icon\" href=\"data:,\">");
    client.println("</head>");
*/

    String html;
    switch(page_id){
      case INDEX_PAGE:
        //client.println("This is the home page");
        html = String(HTML_CONTENT_HOME);
        break;
      case SUBJECT1_PAGE:
        //client.println("This is the Subject1 page");
        html = String(HTML_CONTENT_SUBJECT1);
        break;
      case SPO2_PAGE:
        //client.println("This is the SpO2 page");
         html = String(HTML_CONTENT_LED);
        break;
      case BP_PAGE:
        //client.println("This is the blood pressure page");
        html = String(HTML_CONTENT_DOOR);
        break;
      case ERROR_404_PAGE:
        //client.println("Page Not Found");
        html = String(HTML_CONTENT_404);
        break;
      case ERROR_405_PAGE:
        //client.println("Method Not Allowed");
        html = String(HTML_CONTENT_405);
        break;
    }

    client.println(html);
    client.flush();

    // give the web browser time to receive the data
    delay(10); 

    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
