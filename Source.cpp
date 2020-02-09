#include<iostream>
#include<fstream>

using namespace std;

const int _Max = 101;

int Mokiniai = 0;
int PamokSk = 0;
float DuomMas[_Max][_Max];

void duomIved();
void duomSpausd();
void gerMok();
void kiekMokNeig();

int main()
{
	float duomMas[101][101], mokiniai = 0;

	duomIved();

	return 0;
}

void duomIved()
{
	ifstream ifs("Dalykai.txt");

	while (!ifs.eof())
	{
		ifs >> PamokSk;
		ifs >> Mokiniai;
		for (int i = 0; i < PamokSk; i++)
		{
			for (int g = 0; g < Mokiniai; g++)
			{
				ifs >> DuomMas[i+1][g+1];
			}
		}
	}

	ifs.close();
	duomSpausd();
}

void duomSpausd()
{
	ofstream ofs("Rezultatai.txt");

	ofs << "Mokiniu skaicius: " << PamokSk << endl;
	ofs << "Dalyku skaicius: " << Mokiniai << endl;

	for (int i = 0; i < PamokSk; i++)
	{

		for (int j = 0; j < Mokiniai; j++)
		{
			ofs << i+1 << ". mokinio pazymaiai: " << DuomMas[i+1][j+1] << " ";
			ofs << ";" << endl;
		}
	}

	ofs.close();
	gerMok();
}

void gerMok()
{
	float dMokVid = 0, vid, j = 0;
	
	for (int i = 0; i < PamokSk; i++)
	{
		vid = 0;
		for (int j = 0; j < Mokiniai; j++)
		{
			vid += DuomMas[i+1][j+1];
		}
		j++;
		vid /= Mokiniai;
		if (vid > dMokVid)
		{
			PamokSk = j;
			dMokVid = vid;
		}
	}

	cout << "Geriausiai mokinasi: " << PamokSk << ". mokinys" << endl;
	cout << "Jo vidurkis: " << dMokVid << endl;
}

void kiekMokNeig()
{
	float mMokVid = 10, vid = 0, neig = 0, neigM = 0;

	for (int i = 0; i < PamokSk; i++)
	{
		if (neig > 0)
		{
			neigM++;
		}
		neig = 0;
		vid = 0;
		for (int j = 0; j < Mokiniai; j++)
		{
			vid += DuomMas[i+1][j+1];
			if (4 > DuomMas[i + 1][j + 1])
			{
				neig++;
			}
		}

		vid /= Mokiniai;
		if (vid < mMokVid)
		{
			PamokSk = i;
			mMokVid = vid;
		}
	}

	cout << neigM << " - mokiniu turi neigiamu ivertinimu" << endl;
}