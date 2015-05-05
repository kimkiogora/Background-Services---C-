/**
 * Load Configs from file e.g ini
*/
#include<string>

using namespace std;

class Configs {
public:
	Configs();
	virtual ~Configs(){};
	int getFetchLimit();
	void configure(string);
private:
	void setFetchLimit(int);
protected:
	int f_limit;
};

Configs::Configs() {
	this->configure("daemon.conf");
	int lmt = this->getFetchLimit();
	cout<<"FETCH_LIMIT "<<lmt<<endl;
}

void Configs::configure(string config_file) {
	this->setFetchLimit(10);
}


void Configs::setFetchLimit(int limit) {
	f_limit=limit;
}

int Configs::getFetchLimit() {
	return f_limit;
}
