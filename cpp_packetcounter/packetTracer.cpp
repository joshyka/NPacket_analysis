
#include <iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

int main() {
	string value;
	string sr_no,time,source,destination,info,protocol,len;
	cout << "============INFO=============" << endl; 
	int TCPcounter=0;
	ifstream file( "data.csv" );
	int i=1;
	while ( file.good() )
	{
		getline( file, protocol, ',' );
		protocol=string( protocol, 1, protocol.length()-2 );
		if(protocol=="Protocol"||protocol=="TCP")
		{
			TCPcounter++;
		}
	}
	file.close();
	cout<<"TCP count "<<TCPcounter<<endl;
	return 0;
}

