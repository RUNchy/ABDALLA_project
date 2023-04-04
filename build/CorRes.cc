#include<vector>
#include<cmath>
using namespace std ;
void CorRes()
{
//	TCanvas *c =new TCanvas("hist","hist",1880,980);
	TCanvas *c =new TCanvas();
	auto hist=new TH2F("hist","hist",100,1,12,100,-0.2,1.4);
	vector<double> k,x,d ;
	double value,y,z ;
	fstream file ; 
	file.open("sk6.txt",ios::in);
	while(1)
	{
		file>>value>>y>>z ;
		x.push_back(value);        		/////// contains Energy .
		d.push_back(y*10);            ///////// contains y cor
		k.push_back(z*10);            ////// contains z  cor   . 
		hist->Fill(z*10,y*10);			//////// fill 2-D hist with (y,z) 
		//cout<<y*10 <<"  "<< z*10 <<endl ;
		if(file.eof()) break ;
	}
	
	int dim =size(k);
	vector<double> s1 ,s2; //// s1 contains r for y && s2 for z 
	double sum3=0 ; //// for z cor 
	double sum2=0 ; ////  for y cor 
	double sum1=0 ; //// for Energy 
	
	while((size(s1)<=11098)&& (size(s2)<=11098))
	{
			for(int j=0 ;j<6;j++)
			{
				 sum1+=x.at(j);
				 sum2+=(d.at(j)) *(x.at(j)) ;
				 sum3+=(k.at(j)) *(x.at(j));
			
			}
			s1.push_back(sum2/sum1) ;
			s2.push_back(sum3/sum1);
			cout<<sum2/sum1<<" "<<sum3/sum1<<endl ;
			sum2 =0 ;
			sum1=0 ;	
			sum3 = 0;
			k.erase(k.begin(),k.begin()+6);
			x.erase(x.begin(),x.begin()+6);
			d.erase(d.begin(),d.begin()+6);
		
	}
		
	//hist->SetTitle("Distribution of elctrons in detecors after 5000 runs ;z[mm];y[mm]");
	//hist->Draw("colz");
}


