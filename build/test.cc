#include <filesystem>

void test(){

	
		string line ;
		vector<string> X={"X_10","X_9","X_8","X_7","X_6","X_5","X_4","X_3","X_2","X_1"};
	
	vector<string> Z={"Z_10","Z_9","Z_8","Z_7","Z_6","Z_5","Z_4","Z_3","Z_2","Z_1"} ;
	
	auto c =new TCanvas();
	c->Divide(2,1);



	vector<double> fn_x,fn_z ,fn_yx,fn_yz;
	vector<double> test_x ,test_z , test_yx , test_yz ; 
	for (const auto &id : X ){
		ifstream file("res1.txt");
		string line="" ;
		//cout<<"id : "<<id<<"\t";
		vector<int> chan_vect_x ;
		vector<double> x_vect,yx_vect ;
		int count=0;
		while(getline(file,line)){
			
			
			string temStr, x_str , chan_num_str_x;
			double x,y_x ;
			int chan_num_x ;
			stringstream input(line);
			
			
			getline(input,temStr,',');
			if(temStr == id) {
			temStr="";
			getline(input,temStr,',');
			x=atof(temStr.c_str());
			//cout<<x ;
			temStr="";
			getline(input,temStr,',');
			y_x=atof(temStr.c_str());
			//cout<<y_x<<endl;
			temStr="";
			getline(input,temStr);
			chan_num_x=atoi(temStr.c_str());
			//if(chan_num_x<=153){
			x_vect.push_back(x);
			test_x.push_back(x); //// need to delete 
			chan_vect_x.push_back(chan_num_x);
			test_yx.push_back(y_x); //// need to delete 
			yx_vect.push_back(y_x);
			//}
			//cout << id << "		"<<x<<"		"<<chan_num<<endl;
			temStr="";
			count++ ;
			}
			//else {
			//	getline(input,temStr);
			//}
			line ="";
		
		}
		
	/*	
				
		for(int i=0 ;i<size(x_vect);i++){
			for(int k=i+1;k<size(x_vect);k++){
			
				if(chan_vect_x[i]==chan_vect_x[k]){
				
						chan_vect_x.erase(chan_vect_x.begin()+k);
						yx_vect.erase(yx_vect.begin()+k);
						x_vect.erase(x_vect.begin()+k);
				}
			}
			
		}
		*/


		
		
		double sum_yx =0 , sum1_x=0,sum2_x=0 ;
		//vector<double> s1,s2 ;	
		for(int i=0 ;i<x_vect.size();i++){
					
					sum1_x +=chan_vect_x.at(i) ;
					sum2_x +=(x_vect.at(i)) * (chan_vect_x.at(i)) ;				
					sum_yx +=  yx_vect.at(i);
			}

		fn_x.push_back(sum2_x/sum1_x);
		fn_yx.push_back(sum_yx/size(yx_vect));
		//cout << sum2_x/sum1_x<<sum_yx /size(yx_vect) <<"\t"; 
		
		sum1_x= 0;
		sum2_x = 0;
		sum_yx= 0;
			
		
		
	
	
	}
		c->cd(1);
	
		auto g1 = new TGraph(test_x.size(),&test_x[0],&test_yx[0]);
		g1->SetTitle("Electron track;x cor;y cor");
		g1->GetXaxis()->SetTitleOffset(1.4);
		g1->SetMarkerColor(4);
		g1->SetMarkerStyle(20);
//		g1->DrawGraph(x_vect.size());
		//g1->GetYaxis()->SetRangeUser(0,80);
		g1->Draw("ap");
	

	for (const auto &id : Z ){
		ifstream file("res1.txt");
		string line="" ;
		//cout<<"id : "<<id<<endl;
		vector<int> chan_vect_z ;
		vector<double> z_vect ,yz_vect ;
		int count1=0;
		while(getline(file,line)){
			
			
			string temStr_z ;
			double z,y_z ;
			int chan_num_z;
			stringstream input1(line);
			
			
			getline(input1,temStr_z,',');
			if(temStr_z == id) {
			temStr_z="";
			getline(input1,temStr_z,',');
			z=atof(temStr_z.c_str());
			temStr_z="";
			getline(input1,temStr_z,',');
			y_z=atof(temStr_z.c_str());
			//cout<<y_z<<endl;
			temStr_z="" ;
			getline(input1,temStr_z);
			chan_num_z=atoi(temStr_z.c_str());
			//if(chan_num_z<=153){
			z_vect.push_back(z);
			test_z.push_back(z); /// need to delete 
			chan_vect_z.push_back(chan_num_z);
			yz_vect.push_back(y_z);
			test_yz.push_back(y_z);/// need to delete 
			//}
			//cout << id << "		"<<z<<"		"<<chan_num_z<<endl;
			temStr_z="";
			count1 ++ ;
			}
			//else {
			//	getline(input1,temStr_z);
			//}
			line ="";
		
		}
		
		/*
		
		for(int i=0 ;i<size(z_vect);i++){
			for(int k=i+1;k<size(z_vect);k++){
			
				if(chan_vect_z[i]==chan_vect_z[k]){
				
						chan_vect_z.erase(chan_vect_z.begin()+k);
						yz_vect.erase(yz_vect.begin()+k);
						z_vect.erase(z_vect.begin()+k);
				}
			}
			
		}
		*/
		
		

		double sum_z =0 ,sum1_z=0,sum2_z=0 ;
			
			for(int i=0 ;i<z_vect.size();i++){
					
					sum1_z +=chan_vect_z.at(i) ;
					sum2_z +=(z_vect.at(i)) * (chan_vect_z.at(i)) ;				
					sum_z  +=yz_vect.at(i);
			}
		//cout<<sum2_z/sum1_z<<endl;
		fn_z.push_back(sum2_z/sum1_z);
		fn_yz.push_back(sum_z/size(yz_vect));
		//cout << sum2_z/sum1_z<<endl; 
		sum1_z= 0;
		sum2_z = 0;
		sum_z =0 ;
			//cout<<count<<endl;
			
		
		
	
	
	}
		c->cd(2);
		auto g2 = new TGraph(test_z.size(),&test_z[0],&test_yz[0]);
		g2->SetTitle("Electron track;z cor;y cor");
		g2->SetMarkerColor(4);
		g2->SetMarkerStyle(20);
		//g2->DrawGraph(z_vect.size());
		//g2->GetYaxis()->SetRangeUser(0,80);
		g2->Draw("ap");
	
	for(int i=0 ;i<fn_z.size();i++){
		
		cout<<fn_z.at(i)<<" "<<fn_yz.at(i) <<"	"<<fn_x.at(i)<<" "<<fn_yx.at(i)<<endl;
	
	}
	
}
