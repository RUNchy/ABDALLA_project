#include"math.h"
#include<iomanip>
#include<cmath>
void draw(){
	std::cout << std::fixed;
   std::cout << std::setprecision(7);
   double pi = TMath::Pi();
	auto c =new TCanvas();
	c->Divide(2,1);
	ifstream file("res2.txt");
	double x, z ,y_z,y_x;
	vector<double> z_vect ,x_vect,yx_vect,yz_vect ;
	double sum_xy=0 , sum_zy =0, sum_y_x_sq=0, sum_y_z_sq=0 , sum_x=0 , sum_z=0,sum_x_sq=0, sum_z_sq =0 ,sum_y_x=0,sum_y_z=0;
	while(1)
	{
		file>>z>>y_z>>x>>y_x  ; 
		z_vect.push_back(z*1000);
		x_vect.push_back(x*1000);
		yx_vect.push_back(y_x*1000);
		//cout<<"("<<z<<","<<y_z<<")"<<",";
		//cout<<"("<<z<<","<<y_z<<")"<<",";
		yz_vect.push_back(y_z*1000);
		if(file.eof()) break ;
	}
	for(int i =0; i<size(z_vect);i++){
		sum_y_x +=yx_vect[i] ;
		sum_y_z +=yz_vect[i];
		sum_x +=x_vect[i] ;
		sum_z +=z_vect[i];
		sum_xy +=x_vect[i]*yx_vect[i];
		sum_zy +=z_vect[i]*yz_vect[i];
		sum_x_sq +=pow(x_vect[i],2);
		sum_z_sq +=pow(z_vect[i],2);
	
	}
	//// least square z  /////////////// y_z=(m_z)*z+(b_z)
	double z_avg=sum_z/10 ;
	double y_z_avg=sum_y_z/10; 
	double m_z =(10*sum_zy-sum_z*sum_y_z)/(10*sum_z_sq-pow(sum_z,2));
	//cout<<m_z<<endl;
	//double b_z=(sum_y_z-m_z*sum_z)/10 ;
	//out<<m_z/b_z<<endl;
	//cout<<m_z<<","<<b_z<<endl;
	double y_Zdiff=(yz_vect[0]-yz_vect[9]);
	double x_Zdiff =(z_vect[0]-z_vect[9]);
	double ang_z=atan(x_Zdiff/y_Zdiff);
	//cout<<"ang_z = "<<ang_z*180/pi <<endl;
	//cout<<z_vect[9]<<endl;
	//cout<<z_vect[9]<<" "<<z_vect[0]<<endl;
	double y_Xdiff=(yx_vect[0]-yx_vect[9]);
	double x_Xdiff=(x_vect[0]-x_vect[9]);
	double ang_x=atan(x_Xdiff/y_Xdiff) ;
	//cout<<"ang_x = "<<ang_x*180/pi<<endl;
	//cout<<x_vect[9]<<" "<<x_vect[0]<<endl;
	double m_x =(10*sum_xy-sum_x*sum_y_x)/(10*sum_x_sq-pow(sum_x,2));
	cout<<m_x<<endl;
	c->cd(1);
	
	auto g1 = new TGraph(x_vect.size(),&z_vect[0],&yz_vect[0]);
 	//auto fun1=new TF1("func1","[0]*x+[1]",35,35.5);
 	//fun1->SetParameter(0,m_z);
 	//fun1->SetParameter(1,b_z);	
 	//g1->Fit("func1");
   g1->SetTitle("Electron track;Z cor [mkm];y cor [mkm]");
	g1->GetXaxis()->SetTitleOffset(1.4);
   g1->SetMarkerColor(4);
   g1->SetMarkerStyle(20);
   g1->Fit("pol1");


   g1->Draw("AP");
	

	c->cd(2);
	auto g2 = new TGraph(x_vect.size(),&x_vect[0],&yx_vect[0]);
   g2->SetTitle("Electron track;X cor [mkm];y cor [mkm]");
   g2->SetMarkerColor(4);
   g2->SetMarkerStyle(20);
   g2->Fit("pol1");
   auto func =g2->GetFunction("pol1");
   cout<<atan(func->GetParameter(0))*180/pi<<endl;
   g2->Draw("AP");

}
