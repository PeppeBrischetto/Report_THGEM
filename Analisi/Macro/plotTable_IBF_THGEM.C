void plotTable_IBF_THGEM()
{
   double V, a, b, c, d;
   char buffer[200];
   
   TGraph *gr6=new TGraph(0);
   TGraph *gr7=new TGraph(0);
   TGraph *gr8=new TGraph(0);        
   
   ifstream in1, in2, in3;
   in1.open("thgemScan_THGEM10_20mbar.txt");
   in1.getline(buffer,200);
   in1.getline(buffer,200);
      
   for(int i=0; i<8; i++){
      in1>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr6->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }
   
   in2.open("thgemScan_THGEM10_30mbar.txt");
   in2.getline(buffer,200);
   in2.getline(buffer,200);

   for(int i=0; i<9; i++){
      in2>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr7->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }
 
   in3.open("thgemScan_ROW_THGEM_20mbar.txt");
   in3.getline(buffer,200);
   in3.getline(buffer,200);

   for(int i=0; i<5; i++){
      in3>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr8->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }
 
 
   
  TLegend *leg=new TLegend(0.1,0.7, 0.4,0.9);
  leg->AddEntry(gr6,"Full 30 mbar", "P");
  leg->AddEntry(gr7,"Full 20 mbar", "P");
  leg->AddEntry(gr8,"Row 20 mbar", "P");      
  
  TCanvas *c3a=new TCanvas("C3a");  
  TH2F *bga=new TH2F("bga1","",1000,140,240,1000,0,110);
   bga->SetStats(0);
   bga->GetXaxis()->SetTitle("V_{THGEM} (V)");
   bga->GetYaxis()->SetTitle("IBF (%)");
   bga->Draw();
 
  gr6->SetTitle("IBF");
  gr6->SetMarkerStyle(20);
  gr6->SetMarkerSize(1);
  gr6->SetMarkerColor(kOrange +5);
  gr6->SetLineWidth(1);
  gr6->SetLineColor(kOrange +5);
  gr6->Draw("PL");
 
  gr7->SetTitle("ch6");
  gr7->SetMarkerStyle(20);
  gr7->SetMarkerSize(1);
  gr7->SetMarkerColor(kOrange +3);
  gr7->SetLineWidth(1);
  gr7->SetLineColor(kOrange +3);
  gr7->Draw("PL");
  
  gr8->SetTitle("ch6");
  gr8->SetMarkerStyle(20);
  gr8->SetMarkerSize(1);
  gr8->SetMarkerColor(kGreen +3);
  gr8->SetLineWidth(1);
  gr8->SetLineColor(kGreen +3);
  gr8->Draw("PL");
  
  leg->Draw();  
}
