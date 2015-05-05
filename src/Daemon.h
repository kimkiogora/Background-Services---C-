/**
 * Daemon class.
 * Base class is configs
*/
class Daemon:public Configs {
public:
	Daemon();
	virtual ~Daemon();
	Logger *l;
	void fetchAndProcessRequests();
	void setDebugOn(int status);
	int getDebugMode();
private:
	int bDebug;
};

Daemon::Daemon() {
	l = new Logger;
	l->setDebugMode(this->getDebugMode());
}

Daemon::~Daemon() {
	delete l;
}

void Daemon::setDebugOn(int stat) {
	bDebug = stat;
}

int Daemon::getDebugMode() {
	cout<<"DebugMode is "<<bDebug<<endl;
	return bDebug;
}

void Daemon::fetchAndProcessRequests() {
	l->info("fetchAndProcessRequests()| No requests to process >>>");
}
