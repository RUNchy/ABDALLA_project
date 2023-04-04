#include<cmath>
void hist()
{
	
	
	//TCanvas *c =new TCanvas("hist","hist",1880,980);
	auto c =new TCanvas();
	double pi = TMath::Pi();
	//////// reading out from trees ////////////////// 
	TFile *file =new TFile("output_Range_GeV.root","READ");
	TTree *t10 = (TTree*)file->Get("layer10");
	TTree *t9 = (TTree*)file->Get("layer9");
	TTree *t8 = (TTree*)file->Get("layer8");
	TTree *t7 = (TTree*)file->Get("layer7");
	TTree *t6 = (TTree*)file->Get("layer6");
	TTree *t5 = (TTree*)file->Get("layer5");
	TTree *t4 = (TTree*)file->Get("layer4");
	TTree *t3 = (TTree*)file->Get("layer3");
	TTree *t2 = (TTree*)file->Get("layer2");
	TTree *t1 = (TTree*)file->Get("layer1");
	
	//// hitograms for entries ///// 
	TH1F *hist10 =new TH1F("hist10","hist10",1000,0,1000);
	TH1F *hist9 =new TH1F("hist9","hist9",1000,0,1000);
	TH1F *hist8 =new TH1F("hist8","hist8",1000,0,1000);
	TH1F *hist7 =new TH1F("hist7","hist7",1000,0,1000);
	TH1F *hist6 =new TH1F("hist6","hist6",1000,0,1000);
	TH1F *hist5 =new TH1F("hist5","hist5",1000,0,1000);
	TH1F *hist4 =new TH1F("hist4","hist4",1000,0,1000);
	TH1F *hist3 =new TH1F("hist3","hist3",1000,0,1000);
	TH1F *hist2 =new TH1F("hist2","hist2",1000,0,1000);
	TH1F *hist1=new TH1F("hist1","hist1",1000,0,1000);
	

	int fEvt10,fEvt9,fEvt8,fEvt7,fEvt6,fEvt5,fEvt4,fEvt3,fEvt2,fEvt1 ;
	double fX10,fX9,fX8,fX7,fX6,fX5,fX4,fX3,fX2,fX1 ;
	double fY10,fY9,fY8,fY7,fY6,fY5,fY4,fY3,fY2,fY1 ;
	int fChanN10,fChanN9,fChanN8,fChanN7,fChanN6,fChanN5,fChanN4,fChanN3,fChanN2,fChanN1;
vector<int> fChanN_10,fChanN_9,fChanN_8,fChanN_7,fChanN_6,fChanN_5,fChanN_4,fChanN_3,fChanN_2,fChanN_1; //to fill vectors with corresponding values from trees 
vector<double> fY_10,fY_9,fY_8,fY_7,fY_6,fY_5,fY_4,fY_3,fY_2,fY_1 ;
vector<double> fX_10,fX_9,fX_8,fX_7,fX_6,fX_5,fX_4,fX_3,fX_2,fX_1 ;
	t10->SetBranchAddress("fChanN10",&fChanN10);
	t10->SetBranchAddress("fX10",&fX10);
	t10->SetBranchAddress("fY10",&fY10);
	t10->SetBranchAddress("fEvt10",&fEvt10);
	
	
	t9->SetBranchAddress("fChanN9",&fChanN9);
	t9->SetBranchAddress("fX9",&fX9);
	t9->SetBranchAddress("fY9",&fY9);
	t9->SetBranchAddress("fEvt9",&fEvt9);
	
	
	t8->SetBranchAddress("fChanN8",&fChanN8);
	t8->SetBranchAddress("fX8",&fX8);
	t8->SetBranchAddress("fY8",&fY8);
	t8->SetBranchAddress("fEvt8",&fEvt8);
	
	
	t7->SetBranchAddress("fChanN7",&fChanN7);
	t7->SetBranchAddress("fX7",&fX7);
	t7->SetBranchAddress("fY7",&fY7);
	t7->SetBranchAddress("fEvt7",&fEvt7);


	t6->SetBranchAddress("fChanN6",&fChanN6);
	t6->SetBranchAddress("fX6",&fX6);
	t6->SetBranchAddress("fY6",&fY6);
	t6->SetBranchAddress("fEvt6",&fEvt6);	
	
	
	t5->SetBranchAddress("fChanN5",&fChanN5);
	t5->SetBranchAddress("fX5",&fX5);
	t5->SetBranchAddress("fY5",&fY5);
	t5->SetBranchAddress("fEvt5",&fEvt5);
	
	
	t4->SetBranchAddress("fChanN4",&fChanN4);
	t4->SetBranchAddress("fX4",&fX4);
	t4->SetBranchAddress("fY4",&fY4);
	t4->SetBranchAddress("fEvt4",&fEvt4);
	
	
	t3->SetBranchAddress("fChanN3",&fChanN3);
	t3->SetBranchAddress("fX3",&fX3);
	t3->SetBranchAddress("fY3",&fY3);
	t3->SetBranchAddress("fEvt3",&fEvt3);
	
	
	t2->SetBranchAddress("fChanN2",&fChanN2);
	t2->SetBranchAddress("fX2",&fX2);
	t2->SetBranchAddress("fY2",&fY2);
	t2->SetBranchAddress("fEvt2",&fEvt2);
	
	
	t1->SetBranchAddress("fChanN1",&fChanN1);
	t1->SetBranchAddress("fX1",&fX1);
	t1->SetBranchAddress("fY1",&fY1);
	t1->SetBranchAddress("fEvt1",&fEvt1);
	
	vector<int> ent ;
	int entries10 =t10->GetEntries();
	ent.push_back(entries10);
	int entries9 =t9->GetEntries();
	ent.push_back(entries9);
	int entries8 =t8->GetEntries();
	ent.push_back(entries8);
	int entries7 =t7->GetEntries();
	ent.push_back(entries7);
	int entries6 =t6->GetEntries();
	ent.push_back(entries6);
	int entries5 =t5->GetEntries();
	ent.push_back(entries5);
	int entries4 =t4->GetEntries();
	ent.push_back(entries4);
	int entries3 =t3->GetEntries();
	ent.push_back(entries3);
	int entries2 =t2->GetEntries();
	ent.push_back(entries2);
	int entries1 =t1->GetEntries();
	ent.push_back(entries1);
	
	for(int i =0; i<entries10;i++)
	{
		t10->GetEntry(i);
		fChanN_10.push_back(fChanN10);
		fX_10.push_back(fX10);
		fY_10.push_back(fY10);
		hist10->Fill(fEvt10);
	}	
	for(int i =0; i<entries9;i++)
	{
		t9->GetEntry(i);
		fChanN_9.push_back(fChanN9);
		fX_9.push_back(fX9);
		fY_9.push_back(fY9);
		hist9->Fill(fEvt9);
	}
	for(int i =0; i<entries8;i++)
	{
		t8->GetEntry(i);
		fChanN_8.push_back(fChanN8);
		fX_8.push_back(fX8);
		fY_8.push_back(fY8);
		hist8->Fill(fEvt8);
	}
		
	for(int i =0; i<entries7;i++)
	{
		t7->GetEntry(i);
		fChanN_7.push_back(fChanN7);
		fX_7.push_back(fX7);
		fY_7.push_back(fY7);
		hist7->Fill(fEvt7);
	}
		
	for(int i =0; i<entries6;i++)
	{
		t6->GetEntry(i);
		fChanN_6.push_back(fChanN6);
		fX_6.push_back(fX6);
		fY_6.push_back(fY6);
		hist6->Fill(fEvt6);
	}
	for(int i =0; i<entries5;i++)
	{
		t5->GetEntry(i);
		fChanN_5.push_back(fChanN5);
		fX_5.push_back(fX5);
		fY_5.push_back(fY5);
		hist5->Fill(fEvt5);
	}
		
	for(int i =0; i<entries4;i++)
	{
		t4->GetEntry(i);
		fChanN_4.push_back(fChanN4);
		fX_4.push_back(fX4);
		fY_4.push_back(fY4);
		hist4->Fill(fEvt4);

	}
	for(int i =0; i<entries3;i++)
	{
		t3->GetEntry(i);
		fChanN_3.push_back(fChanN3);
		fX_3.push_back(fX3);
		fY_3.push_back(fY3);
		hist3->Fill(fEvt3);
	}	
	for(int i =0; i<entries2;i++)
	{
		t2->GetEntry(i);
		fChanN_2.push_back(fChanN2);
		fX_2.push_back(fX2);
		fY_2.push_back(fY2);
		hist2->Fill(fEvt2);
	}
		
	for(int i =0; i<entries1;i++)
	{
		t1->GetEntry(i);
		fChanN_1.push_back(fChanN1);
		fX_1.push_back(fX1);
		fY_1.push_back(fY1);
		hist1->Fill(fEvt1);
	}

	int temp= 0;
	vector<double> x_10, x_9 ,x_8,x_7,x_6,x_5,x_4,x_3,x_2,x_1 ;
	vector<double> y_10,y_9,y_8,y_7,y_6,y_5,y_4,y_3,y_2,y_1 ;
	for(int i=1 ;i<=hist10->GetNbinsX();i++){
	int c=hist10->GetBinContent(i);
	double sum_x1 =0,sum_x2 =0,sum_y=0;
		for(int j=0;j<c;j++){
			sum_x1 +=fChanN_10.at(j) ;
			sum_x2 +=(fChanN_10.at(j)) * (fX_10.at(j)) ;				
			sum_y +=  fY_10.at(j);
		}
		fChanN_10.erase(fChanN_10.begin(),fChanN_10.begin()+c);
		fX_10.erase(fX_10.begin(),fX_10.begin()+c);
		fY_10.erase(fY_10.begin(),fY_10.begin()+c);
		x_10.push_back(sum_x2 /sum_x1);
		y_10.push_back(sum_y/c);
	}
	for(int i=1 ;i<=hist9->GetNbinsX();i++){
	int c=hist9->GetBinContent(i);
	double sum_x1 =0,sum_x2 =0,sum_y=0;
		for(int j=0;j<c;j++){
			sum_x1 +=fChanN_9.at(j) ;
			sum_x2 +=(fChanN_9.at(j)) * (fX_9.at(j)) ;				
			sum_y +=  fY_9.at(j);
		}
		fChanN_9.erase(fChanN_9.begin(),fChanN_9.begin()+c);
		fX_9.erase(fX_9.begin(),fX_9.begin()+c);
		fY_9.erase(fY_9.begin(),fY_9.begin()+c);
		x_9.push_back(sum_x2 /sum_x1);
		y_9.push_back(sum_y/c);
	}
	for(int i=1 ;i<=hist8->GetNbinsX();i++){
	int c=hist8->GetBinContent(i);
	double sum_x1 =0,sum_x2 =0,sum_y=0;
		for(int j=0;j<c;j++){
			sum_x1 +=fChanN_8.at(j) ;
			sum_x2 +=(fChanN_8.at(j)) * (fX_8.at(j)) ;				
			sum_y +=  fY_8.at(j);
		}
		fChanN_8.erase(fChanN_8.begin(),fChanN_8.begin()+c);
		fX_8.erase(fX_8.begin(),fX_8.begin()+c);
		fY_8.erase(fY_8.begin(),fY_8.begin()+c);
		x_8.push_back(sum_x2 /sum_x1);
		y_8.push_back(sum_y/c);
	}
	for(int i=1 ;i<=hist7->GetNbinsX();i++){
	int c=hist7->GetBinContent(i);
	double sum_x1 =0,sum_x2 =0,sum_y=0;
		for(int j=0;j<c;j++){
			sum_x1 +=fChanN_7.at(j) ;
			sum_x2 +=(fChanN_7.at(j)) * (fX_7.at(j)) ;				
			sum_y +=  fY_7.at(j);
		}
		fChanN_7.erase(fChanN_7.begin(),fChanN_7.begin()+c);
		fX_7.erase(fX_7.begin(),fX_7.begin()+c);
		fY_7.erase(fY_7.begin(),fY_7.begin()+c);
		x_7.push_back(sum_x2 /sum_x1);
		y_7.push_back(sum_y/c);
	}
	for(int i=1 ;i<=hist6->GetNbinsX();i++){
	int c=hist6->GetBinContent(i);
	double sum_x1 =0,sum_x2 =0,sum_y=0;
		for(int j=0;j<c;j++){
			sum_x1 +=fChanN_6.at(j) ;
			sum_x2 +=(fChanN_6.at(j)) * (fX_6.at(j)) ;				
			sum_y +=  fY_6.at(j);
		}
		fChanN_6.erase(fChanN_6.begin(),fChanN_6.begin()+c);
		fX_6.erase(fX_6.begin(),fX_6.begin()+c);
		fY_6.erase(fY_6.begin(),fY_6.begin()+c);
		x_6.push_back(sum_x2 /sum_x1);
		y_6.push_back(sum_y/c);
	}
	for(int i=1 ;i<=hist5->GetNbinsX();i++){
	int c=hist5->GetBinContent(i);
	double sum_x1 =0,sum_x2 =0,sum_y=0;
		for(int j=0;j<c;j++){
			sum_x1 +=fChanN_5.at(j) ;
			sum_x2 +=(fChanN_5.at(j)) * (fX_5.at(j)) ;				
			sum_y +=  fY_5.at(j);
		}
		fChanN_5.erase(fChanN_5.begin(),fChanN_5.begin()+c);
		fX_5.erase(fX_5.begin(),fX_5.begin()+c);
		fY_5.erase(fY_5.begin(),fY_5.begin()+c);
		x_5.push_back(sum_x2 /sum_x1);
		y_5.push_back(sum_y/c);
	}
	for(int i=1 ;i<=hist4->GetNbinsX();i++){
	int c=hist4->GetBinContent(i);
	double sum_x1 =0,sum_x2 =0,sum_y=0;
		for(int j=0;j<c;j++){
			sum_x1 +=fChanN_4.at(j) ;
			sum_x2 +=(fChanN_4.at(j)) * (fX_4.at(j)) ;				
			sum_y +=  fY_4.at(j);
		}
		fChanN_4.erase(fChanN_4.begin(),fChanN_4.begin()+c);
		fX_4.erase(fX_4.begin(),fX_4.begin()+c);
		fY_4.erase(fY_4.begin(),fY_4.begin()+c);
		x_4.push_back(sum_x2 /sum_x1);
		y_4.push_back(sum_y/c);
	}
	for(int i=1 ;i<=hist3->GetNbinsX();i++){
	int c=hist3->GetBinContent(i);
	double sum_x1 =0,sum_x2 =0,sum_y=0;
		for(int j=0;j<c;j++){
			sum_x1 +=fChanN_3.at(j) ;
			sum_x2 +=(fChanN_3.at(j)) * (fX_3.at(j)) ;				
			sum_y +=  fY_3.at(j);
		}
		fChanN_3.erase(fChanN_3.begin(),fChanN_3.begin()+c);
		fX_3.erase(fX_3.begin(),fX_3.begin()+c);
		fY_3.erase(fY_3.begin(),fY_3.begin()+c);
		x_3.push_back(sum_x2 /sum_x1);
		y_3.push_back(sum_y/c);
	}
	for(int i=1 ;i<=hist2->GetNbinsX();i++){
	int c=hist2->GetBinContent(i);
	double sum_x1 =0,sum_x2 =0,sum_y=0;
		for(int j=0;j<c;j++){
			sum_x1 +=fChanN_2.at(j) ;
			sum_x2 +=(fChanN_2.at(j)) * (fX_2.at(j)) ;				
			sum_y +=  fY_2.at(j);
		}
		fChanN_2.erase(fChanN_2.begin(),fChanN_2.begin()+c);
		fX_2.erase(fX_2.begin(),fX_2.begin()+c);
		fY_2.erase(fY_2.begin(),fY_2.begin()+c);
		x_2.push_back(sum_x2 /sum_x1);
		y_2.push_back(sum_y/c);
	}
	for(int i=1 ;i<=hist1->GetNbinsX();i++){
	int c=hist9->GetBinContent(i);
	double sum_x1 =0,sum_x2 =0,sum_y=0;
		for(int j=0;j<c;j++){
			sum_x1 +=fChanN_1.at(j) ;
			sum_x2 +=(fChanN_1.at(j)) * (fX_1.at(j)) ;				
			sum_y +=  fY_1.at(j);
		}
		fChanN_1.erase(fChanN_1.begin(),fChanN_1.begin()+c);
		fX_1.erase(fX_1.begin(),fX_1.begin()+c);
		fY_1.erase(fY_1.begin(),fY_1.begin()+c);
		x_1.push_back(sum_x2 /sum_x1);
		y_1.push_back(sum_y/c);
	}
	
	vector<double> ang_vect ;
	double tang ;
	for(int j =0 ;j<size(y_1);j++){
		double sum_xy1=0,sum_x=0,sum_x_sq=0 ,sum_y=0 ; 
				sum_xy1 = x_10[j]*y_10[j]+ x_9[j]*y_9[j]+ x_8[j]*y_8[j]+ x_7[j]*y_7[j]+ x_6[j]*y_6[j]+ x_5[j]*y_5[j]+ x_4[j]*y_4[j]+ x_3[j]*y_3[j]+ x_2[j]*y_2[j]+ x_1[j]*y_1[j] ;
				sum_x =x_10[j]+x_9[j]+x_8[j]+x_7[j]+x_6[j]+x_5[j]+x_4[j]+x_3[j]+x_2[j]+x_1[j] ;
				sum_y = y_10[j]+y_9[j] + y_8[j]+y_7[j]+y_6[j]+y_5[j]+y_4[j]+y_3[j]+y_2[j]+y_1[j] ;
			sum_x_sq =pow(x_10[j],2)+pow(x_9[j],2)+pow(x_8[j],2)+pow(x_7[j],2)+pow(x_6[j],2)+pow(x_5[j],2)+pow(x_4[j],2)+pow(x_3[j],2)+pow(x_2[j],2)+pow(x_1[j],2) ;
				

		tang=(10*sum_xy1-sum_x*sum_y) / (10*sum_x_sq-pow(sum_x,2));
		ang_vect.push_back(atan(tang)*180/pi);
	}
	
	auto ang=new TH1F("hist_Range_GeV","hist_Range_GeV",100,30,150);
	for(int i=0;i<size(ang_vect);i++){
		if(ang_vect[i] <0 ) {ang->Fill(ang_vect[i]+180);}
		else ang->Fill(abs(ang_vect[i]));
	}
	TFile *file1=new TFile("hist_res.root","UPDATE");
	ang->Write();
	file->Write();
	
	
	
	
	
	
	
	
	
	
	
	/*
	for(int i=1 ;i<=hist->GetNbinsX();i++){
	int c=hist->GetBinContent(i);
	cout<<c<<endl;
	}
	hist->Draw();

*/
	//cout <<"count= "<<count+count1 <<endl;

//	cout<<hist->GetNbinsX()<<endl;
	/*
	for(int i=0 ;i<hist->GetNbinsX();i++){
		int c=hist->GetBinContent(i);
//		cout<<c<<endl;
		hist0->Fill(c);
	}

	hist0->Draw();
	//hist->Draw("lego");
	//c->Print("c.png");
	
*/

}
