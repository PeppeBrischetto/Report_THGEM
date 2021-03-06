void plotTable_IBF_GAIN()
{
   double V, a, b, c, d;
   char buffer[200];

   float fac1=2.33e-4;   // 10 mbar
   
   TGraph *gr6=new TGraph(0);
   TGraph *gr7=new TGraph(0);
   TGraph *gr8=new TGraph(0);
   TGraph *gr9=new TGraph(0);
   TGraph *gr10=new TGraph(0);
   
   ifstream in1, in2, in3, in4, in5;
   in1.open("../Table/thgemScan_ROW_THGEM_10mbar.txt");
   in1.getline(buffer,200);
      
   for(int i=0; i<11; i++){
      in1>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t\t"<<d<<endl;
      
      gr6->SetPoint(i, -a/fac1, -d/(a+b)*100);  	//anode + top3
   }
   in2.open("../Table/thgemScan_ROW_asymm_r613-624.txt");
   in2.getline(buffer,200);
   
   cout<<"----------------------------------"<<endl;
   for(int i=0; i<12; i++){
      in2>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t\t"<<d<<endl;
      
      gr7->SetPoint(i, -a/fac1, -d/(a+b)*100);  	//anode + top3
   }

   in3.open("../Table/thgemScan_ROW_asymm_r625-632.txt");
   in3.getline(buffer,200);
   cout<<"----------------------------------"<<endl;
   for(int i=0; i<8; i++){
      in3>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t\t"<<d<<endl;
      
      gr8->SetPoint(i, -a/fac1, -d/(a+b)*100);  	//anode + top3
   }

   in4.open("../Table/thgemScan_ROW_symm_r638-647.txt");
   in4.getline(buffer,200);
   cout<<"----------------------------------"<<endl;
   for(int i=0; i<9; i++){
      in4>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t\t"<<d<<endl;
      
      gr9->SetPoint(i, -a/fac1, -d/(a+b)*100);  	//anode + top3
   }

   in5.open("../Table/thgemScan_ROW_asymm_r649-656.txt");
   in5.getline(buffer,200);
   cout<<"----------------------------------"<<endl;
   for(int i=0; i<8; i++){
      in5>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t\t"<<d<<endl;
      
      gr10->SetPoint(i, -a/fac1, -d/(a+b)*100);  	//anode + top3
   }
   
  TLegend *leg=new TLegend(0.7,0.7, 0.9,0.9);
  leg->AddEntry(gr6,"Row symm", "P");
  leg->AddEntry(gr7,"Row asymm", "P");
  leg->AddEntry(gr8,"Row asymm 2", "P");
  leg->AddEntry(gr9,"Row symm V_{drift}=700V", "P");
  leg->AddEntry(gr10,"Row asymm V_{drift}=700V", "P");      
  
  TCanvas *c3a=new TCanvas("C3a");
  c3a->SetLogx();
  c3a->SetGridx();
  c3a->SetGridy();

  TH2F *bga=new TH2F("bga1","",1000,100,100000,1000,0,200);
   bga->SetStats(0);
   bga->GetXaxis()->SetTitle("GAIN");
   bga->GetYaxis()->SetTitle("IBF (%)");
   bga->Draw();
 
  gr6->SetTitle("IBF vs GAIN");
  gr6->SetMarkerStyle(20);
  gr6->SetMarkerSize(1);
  gr6->SetMarkerColor(kOrange +5);
  gr6->SetLineWidth(1);
  gr6->SetLineColor(kOrange +5);
  gr6->Draw("PL");
  
  gr7->SetMarkerStyle(20);
  gr7->SetMarkerSize(1);
  gr7->SetMarkerColor(kGreen +3);
  gr7->SetLineWidth(1);
  gr7->SetLineColor(kGreen +3);
  gr7->Draw("PL");

  gr8->SetMarkerStyle(20);
  gr8->SetMarkerSize(1);
  gr8->SetMarkerColor(kAzure +3);
  gr8->SetLineWidth(1);
  gr8->SetLineColor(kAzure +3);
  gr8->Draw("PL");

  gr9->SetMarkerStyle(20);
  gr9->SetMarkerSize(1);
  gr9->SetMarkerColor(kRed +0);
  gr9->SetLineWidth(1);
  gr9->SetLineColor(kRed +0);
  gr9->Draw("PL");

  gr10->SetMarkerStyle(20);
  gr10->SetMarkerSize(1);
  gr10->SetMarkerColor(kBlue +0);
  gr10->SetLineWidth(1);
  gr10->SetLineColor(kBlue +0);
  gr10->Draw("PL");

  leg->Draw();  
}
