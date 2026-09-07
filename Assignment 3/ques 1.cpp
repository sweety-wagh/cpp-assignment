#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;
typedef unsigned long long RequestId;

using Header = pair<string, string>;
using HeaderList = vector<Header>;
using Port = unsigned int;
using IPAddress = string;


enum class HttpStatus {
	 OK = 200,
	 Created = 201,
	 BadRequest = 400,
	 Unauthorized = 401,
	 NotFound = 404,
	 ServerError = 500
};


void handleResponse(HttpStatus status, const string& endpoint){
	const int curr_stat_code = static_cast<int>(status);

	switch(curr_stat_code){
	case 200:
		cout<<endpoint<<" "<<"200 OK : Request successful"<<endl;
		break;
	case 201:
		cout<<endpoint<<" "<<"200 Created: Successfully Created"<<endl;
			break;
	case 400:
		cout<<endpoint<<" "<<"400 BadRequest : retry later"<<endl;
			break;
	case 401:
		cout<<endpoint<<" "<<"401 Unauthorized : Authentication required"<<endl;
			break;
	case 404:
		cout<<endpoint<<" "<<"404 Not Found : Endpoint does not exist"<<endl;
			break;
	case 500:
		cout<<endpoint<<" "<<"500 Server Error : Internal server error — retry later"<<endl;
			break;
	}
}

void printHeaders(const HeaderList& headers){
	for(auto& p : headers){
		cout<<p.first<<" : "<<p.second<<endl;
	}

}


int main() {
	HeaderList h1 = {{"Content-Type", "application/json"}, {"Authorization", "Bearer eyJhbGci"}, {"Accept-Language", "en-US"}};
	Port p = 8080;
	RequestId id = 1748293847;
	cout<<"Request ID: "<<id<<endl;
	cout<<"Server Port: "<<p<<endl;
	cout<<endl;
	cout<<"Headers: "<<endl;
	printHeaders(h1);
	return 0;
}
