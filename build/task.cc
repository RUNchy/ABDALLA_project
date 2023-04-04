#include <filesystem>
#include <TMath.h>
void task()
{
	//auto c =new TCanvas("c","c",1880,980);
	auto c =new TCanvas();
	auto hist1 =new TH1I("Track multiplicity","Track multiplicity",9,0,11);
	auto hist2=new TH2D("Muon Tracks' angles","Muon Tracks' angles",20,-30,-30,20,30,-30);
	c->Divide(3,1);
	vector<double> x_cor,z_cor,z_chan,x_chan ;
	//vector<double> x_f,y_f,z_f ;
	vector<ULong64_t> name ;
	const string DataDirName = "data/";
	ULong64_t mEventId ;
	string res ="_res.txt";
	//string TrLc="_Tracks.csv" ;
	 for (const auto& DataFile : filesystem::directory_iterator("data_10/"))
	 {
		string DataFileName_vert = DataFile.path().filename();
		size_t Res_txt = DataFileName_vert.find("_res.txt");
		if (Res_txt == string::npos) continue;
		mEventId = stoull( DataFileName_vert.substr(0, Res_txt) );
		name.push_back(mEventId); 	
	 }
  for (const auto& id : name)
  {
  		string x1 ="data_10/"+to_string(id)+res ;
  		ifstream file1(x1) ;   
  		string line="" ;
  		while(getline(file1,line))
  		{
  			int mult ;
  			string tempStr="" ;
  			stringstream input(line);
  			

				  		getline(input,tempStr,',');
			  			getline(input,tempStr,',');
			  			getline(input,tempStr,',');
  			  			getline(input,tempStr,',');
  			  			getline(input,tempStr,',');
  						getline(input,tempStr,',');
  						getline(input,tempStr,',');
  		  				getline(input,tempStr,',');
  		  				tempStr="";
  		  				getline(input,tempStr,',');
  		  				//cout<<tempStr<<endl;
  		  				mult =atoi(tempStr.c_str());
  		  				//cout<<mult<<endl;
  		  				hist1->Fill(mult);
  		  				tempStr="" ;
		}
		
		while(getline(file2,line))
		{
				int trType ;
				double AngXZ, AngYZ ;
				string temStr="";
				stringstream input1(line);
				
				getline(input1, temStr,',');
				trType =atoi(temStr.c_str());
				if (trType != 1) continue ;
				getline(input1, temStr,',');
				getline(input1, temStr,',');
				getline(input1, temStr,',');
				temStr="";
				getline(input1, temStr,',');
				AngXZ=atof(temStr.c_str());
				temStr="";
				getline(input1, temStr,',');
				AngYZ=atof(temStr.c_str());
				hist2->Fill((AngXZ*180)/(TMath::Pi()),(AngYZ*180)/(TMath::Pi()));
				//cout<<"AngXZ = "<<AngXZ <<"AngYZ =  "<<AngYZ<<endl;
		}
		}
		
		c->cd(1);
		hist1->SetFillColor(2);
		hist1->SetTitle("Multiplicity distribution;Multiplicity N ; Counts");
		hist1->Draw();
		c->cd(2);
		hist2->GetXaxis()->SetTitle("AngXZ");
		hist2->GetYaxis()->SetTitle("AngYZ");
		hist2->GetZaxis()->SetTitle("Counts");
		hist2->GetXaxis()->SetTitleOffset(1.4);
		hist2->GetYaxis()->SetTitleOffset(1.8);
		hist2->GetZaxis()->SetTitleOffset(1.4);
		hist2->SetTitle("Muon Tracks' angles distribution");
		gStyle->SetPalette(1);
		hist2->Draw("lego2");
		c->cd(3);
		hist2->GetXaxis()->SetTitle("AngXZ");
		hist2->GetYaxis()->SetTitle("AngYZ");
		hist2->GetZaxis()->SetTitle("Counts");
		hist2->GetXaxis()->SetTitleOffset(1.4);
		hist2->GetYaxis()->SetTitleOffset(1.8);
		hist2->GetZaxis()->SetTitleOffset(1.4);
		hist2->SetTitle("Muon Tracks' angles distribution");
		gStyle->SetPalette(1);
		hist2->Draw("colz");
		//c->Print("task.png");
		
}
