void test10(){
	TFile *file =new TFile("output_10G_t0.root","READ");
	TTree *t10 = (TTree*)file->Get("layer10");
	int entries10=t10->GetEntries();
	int fEvt10 ;
	t10->SetBranchAddress("fEvt10",&fEvt10);
	TH1F *hist10 =new TH1F("hist10","hist10",10,0,10);
	for(int i =0; i<entries10;i++)
	{
		t10->GetEntry(i);
		//fChanN_10.push_back(fChanN10);
		//fX_10.push_back(fX10);
		//fY_10.push_back(fY10);
		hist10->Fill(fEvt10);
	}	
	for(int i=1;i<=hist10->GetNbinsX();i++){
		cout<<hist10->GetBinContent(i)<<endl;
	}


}
