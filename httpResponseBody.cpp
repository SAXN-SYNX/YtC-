#include <iostream>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPMessage.h>
#include <Poco/URI.h>

using namespace std;
using namespace Poco;
using namespace Poco::Net;

int main()
{
    // Create a URI
    URI uri("http://httpbin.org");
    // Create a session
    HTTPClientSession session(uri.getHost(), uri.getPort());
    // Set connection to keepalive
    session.setKeepAlive(true);
    // Choose the http request method
    HTTPRequest request(HTTPRequest::HTTP_GET, "/", HTTPMessage::HTTP_1_1);
    // Add headers
    request.add("User-Agent", "Mozilla/5.0");
    // Send the request
    session.sendRequest(request);
    // Receive response
    HTTPResponse response;
    istream &page = session.receiveResponse(response);
    // Store received body
    string received = ""; // Store the body in string
    string tmp; // Temporary variable
    while(getline(page,tmp))    // Loop into each line of page
    {
        received += tmp + "\n";     // Insert each line into variable received with endline
    }
    // Print the stored body
    cout << received << endl;
    // Now compile the code and open wireshark
    
    
    
    return 0;
    
}
