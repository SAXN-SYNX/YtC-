#include <iostream>
#include <Poco/URI.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPMessage.h>

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
    
    // Print the status code
    cout << response.getStatus() << endl;
    
    // Lets compile and start wireshark 
    
    return 0;
}
