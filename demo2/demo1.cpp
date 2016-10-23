#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <Windows.h>
#include <Shlwapi.h>
#pragma comment(lib,"Shlwapi.lib")
#include <fstream>
#include <fstream>
#include <sstream>
using namespace std;

// Í¨¹ýwindows apiÉèÖÃ¿ØÖÆÌ¨µÄÑÕÉ«
#define FG_RED FOREGROUND_INTENSITY | FOREGROUND_RED
#define FG_GREEN FOREGROUND_INTENSITY | FOREGROUND_GREEN
#define FG_GRAY FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE

// ºê(ºêµÄÊ¹ÓÃ)
#define LOK LOG(OK)
#define LERR LOG(ERR)
#define LINFO LOG(INFO)


// Ã¶¾ÙÀàµÄÊ¹ÓÃ
enum LV
{
	INFO,
	ERR,
	OK
};

//¶¨ÒåÊä³ö¼¶±ðÀà
class LOG
{
public:
	//³ÉÔ±ÊôÐÔ
	LV m_lv;
	//¶¨ÒåÒ»¸ö¾ä±ú
	HANDLE m_handle;
	LOG(LV lv) {
		m_lv = lv;
		//»ñÈ¡±ê×¼Êä³ö¾ä±ú
		m_handle = GetStdHandle(STD_OUTPUT_HANDLE);
		if (m_lv == ERR)
		{
			SetConsoleTextAttribute(m_handle, FG_RED);
		}else if (m_lv == OK)
		{
			SetConsoleTextAttribute(m_handle, FG_GREEN);
		}
		else {
			SetConsoleTextAttribute(m_handle, FG_GRAY);
		}
	}
	//²Ù×÷·ûÖØÔØ
	operator char*(){
		return "";
	}
	~LOG() {
		// ÉèÖÃ³É¿ØÖÆÌ¨×Ô¼ºµÄÑÕÉ«
		SetConsoleTextAttribute(m_handle, FG_GRAY);
	}
};

//¶¨ÒåÍ¼ÊéÊÇ·ñ½è³ö
enum STATUS
{
	IN_STATUS,
	NO_STATUS
};

//¶¨ÒåÍ¼ÊéÀà
class  Books
{
public:
	Books(int inputId, string inputName,STATUS inputStatus = IN_STATUS) {
		id = inputId;
		name = inputName;
		status = inputStatus;
	}
	int id;
	string name;
	STATUS status;
};


// ¸øº¯ÊýÈ¡±ðÃû
typedef vector<string> STR_ARR;
// ÇÐ¸î×Ö·û´®
STR_ARR split(string sourceStr) {
	//ËéÆ¬»º³å
	string chunkBuffer = "";
	//·µ»Ø×Ö·û
	STR_ARR totalChunk;
	// C++11
	// ¶ÔÓÚÃ¿Ò»¸ösourceStrµ±ÖÐµÄ×Ö·û´®£¬±éÀúÖ®
	for each(char c in sourceStr) {
		//ÅÐ¶ÏÊÇ·ñÎª¿Õ¸ñ
		if (c == ' ') {
			//Èç¹ûÊÇ¿Õ¸ñ£¿
			if (chunkBuffer != "")
			{
				//°Ñµ±Ç°µÄ»º³å´æÆðÀ´
				totalChunk.push_back(chunkBuffer);
				chunkBuffer = "";
			}
		}
		// ²»ÊÇ¿Õ¸ñ
		else {
			// ×Ô¼Ó
			chunkBuffer += c;
		}
	}
	if (chunkBuffer != "")
	{
		totalChunk.push_back(chunkBuffer);
	}
	return totalChunk;
}

// class´´½¨Ò»¸öÍ¼ÊéÀà
class BookSys
{
public:
	int lastId;
	BookSys() {
		lastId = 0;
	}
	//»ñÈ¡ÎÄ¼þÂ·¾¶£¨c:\123.txt£©
	string getDbPath() {
		//»ñÈ¡×Ô¼ºµÄÂ·¾¶
		char buff[MAX_PATH];
		GetModuleFileName(NULL, buff, MAX_PATH);
		//»ñÈ¡×Ô¼ºµÄÎÄ¼þ¼Ð
		PathRemoveFileSpec(buff);
		//Á´½ÓÊý¾Ý¿âÎÄ¼þÃû
		PathAppend(buff, "bookSysDb.txt");
		return buff;
	}
	//Ö´ÐÐËùÓÐÃüÁîÈë¿Ú
	void runCommond(string input) {
		STR_ARR retStr = split(input);
		if (retStr.size() <= 0)
		{
			cout << LERR << "Syntax error:" << " commond in not empty." << endl;
			return;
		}
		//»ñÈ¡Ö´ÐÐÃüÁî
		string commond = retStr[0];
		if (commond == "reg")
		{
			reg(retStr);
		}
		else if (commond == "login") {
			login(retStr);
		}
		else if (commond == "addbook") {
			addbook(retStr);
		}
		else if (commond == "listbooks") {
			listbooks(retStr);
		}
		else if (commond == "savedb")
		{
			savedb(retStr);
		}else if (commond == "loadDb")
		{
			loadDb(retStr);
		}
	}
	void reg(STR_ARR retStr) {
		// ÓïÒå reg username password
		// reg henry 123
		if (retStr.size() < 3)
		{
			cout << LERR << "Syntax error:" << "reg 2 params username and password." << endl;
			return;
		}
		// È¡³öuserName
		string userName = retStr[1];
		//È¡³öpassword
		string password = retStr[2];
		if (bookDataBace.find(userName) == bookDataBace.end())
		{
			//Ìí¼Óµ½bookDataBace
			bookDataBace[userName] = password;
			cout << LOK << userName << " insert successfully." << endl;
		}
		else {
			//ÓÃ»§ÒÑ¾­´æÔÚÁË
			cout << LERR << "The user " << userName << " has been register." << endl;
			return;
		}
		return;
	}
	//µÇÂ¼ÏµÍ³
	void login(STR_ARR retStr) {
		if (retStr.size() < 3)
		{
			cout << LERR << "Syntax error:" << "login 2 params username and password." << endl;
			return;
		}
		string userName = retStr[1];
		string password = retStr[2];
		//¼ì²éÓÃ»§ÊÇ·ñ´æÔÚ
		if (bookDataBace.find(userName) == bookDataBace.end())
		{
			//ÓÃ»§²»´æÔÚ
			cout << LERR << "The user" << userName << "is not found." << endl;
		}
		else {
			//´æÔÚ
			//ÃÜÂëÊÇ·ñÆ¥Åä
			if (bookDataBace[userName] == password)
			{
				cout << LOK << "The user " << userName << " is login in." << endl;
			}
			else {
				cout << LERR << "The user " << userName << " password error." << endl;
			}
		}
	}

	//Ìí¼ÓÍ¼Êé
	void addbook(STR_ARR retStr) {
		if (retStr.size() < 3)
		{
			cout << LERR << "Syntax error:" << "addbook 2 params book name and number." << endl;
			return;
		}
		string name = retStr[1];
		string countStr = retStr[2];
		for (int i = 0; i < 5; i++) {
			lastId++;
			Books newBook(lastId, name);
			bookDB.push_back(newBook);
		}
		cout << LOK << "addbook successfully." << endl;
	}
	//²éÑ¯ËùÓÐµÄÍ¼Êé
	void listbooks(STR_ARR retStr) {
		for each(Books book in bookDB) {
			cout << book.id << "   <<" << book.name << ">>" << endl;
		}
	}

	// ´´½¨Ò»¸ö¼òÒ×µÄÊý¾Ý¿â
	map<string, string> bookDataBace;
	vector<Books> bookDB;

	//°ÑÊý¾ÝÊä³öµ½´ÅÅÌÖÐ
	void savedb(STR_ARR retStr) {
		//»ñÈ¡ÎÄ¼þÂ·¾¶
		string dbPath = getDbPath();
		//Êä³öÎÄ¼þÁ÷
		//output file stream
		ofstream output(dbPath);
		//±£´æÓÃ»§ÐÅÏ¢
		for each(auto users in bookDataBace) {
			output << "USER" << " " << users.first << " " << users.second << endl;
		}
		//±£´æÍ¼ÊéÐÅÏ¢
		for each(auto book in bookDB) {
			output << "BOOKS" << " " << book.id << " " << book.name << " " << book.status << endl;
		}
		output.close();
	}
	//´Ó´ÅÅÌÖÐ¶Á³öÊý¾Ý
	void loadDb(STR_ARR retStr) {
		load_local();
	}
	void load_local() {
		//»ñÈ¡ÎÄ¼þÂ·¾¶
		string dbPath = getDbPath();
		//ÊäÈëÎÄ¼þÁ÷
		// input file stream
		ifstream input(dbPath);
		//Ñ­»·È¡³ö
		while (!input.eof())
		{
			string currLine;
			getline(input, currLine);
			//ÇÐ¸î×Ö·û´®
			STR_ARR ret = split(currLine);
			if (ret.size() <= 0)
			{
				break;
			}
			if (ret[0] == "USER") {
				string userName = ret[1];
				string password = ret[2];
				bookDataBace[userName] = password;
			}else if (ret[0] == "BOOKS")
			{
				string idStr = ret[1];
				string name = ret[2];
				string statusStr = ret[3];
				int id;
				istringstream(idStr) >> id;
				STATUS status;
				istringstream(statusStr) >> (int&)status;
				Books newBook(id, name, status);
				bookDB.push_back(newBook);
			}
		}
	}
};






int main() {
	//cout << LOG(ERR) << "ERROR" << endl;
	// ÔÚÍâÃæÉùÃ÷ÁËÀà£¬ÏÖÔÚµ÷ÓÃ
	BookSys bookSys;
	bookSys.load_local();
	//string dbPath = bookSys.getDbPath();
	cout << LOK << "=======================" << endl;
	cout << LOK << "  C++¹«¿ª¿Î(µÚ¶þ¿Î)" << endl;
	cout << LOK << "  Henry" << endl;
	cout << LOK << "  ¶þ©–Ò»ÁùÄêÊ®ÔÂ¶þÊ®¶þÈÕ 11:01:19" << endl;
	cout << LOK << "=======================" << endl;
	// ÊäÈë»º³å
	string inputBufer;
	do 
	{
		// ´òÓ¡ÌáÊ¾·û
		cout << "BOOKSYS > ";
		// cin >> inputBufer;
		getline(cin, inputBufer);
		// Ê¹ÓÃÀàµÄ×¢²á·½·¨
		bookSys.runCommond(inputBufer);



	} while (inputBufer !="exit");
	system("pause");
	return 0;
}