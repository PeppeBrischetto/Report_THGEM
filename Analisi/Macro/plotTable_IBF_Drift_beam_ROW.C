void plotTable_IBF_Drift_beam_ROW()
{
   double V, a, b, c, d;
   char buffer[200];
   
   TGraph *gr6=new TGraph(0);
   TGraph *gr7=new TGraph(0);
   TGraph *gr8=new TGraph(0);
   TGraph *gr9=new TGraph(0);
   TGraph *gr10=new TGraph(0);
   TGraph *gr11=new TGraph(0);
   TGraph *gr12=new TGraph(0);
                
   
   ifstream in1, in2, in3, in4, in5, in6, in7;
   in1.open("driftScan_ROW_THGEM_20mbar-Ibeam400pA-2020-03-10.txt");
   in1.getline(buffer,200);
      
   for(int i=0; i<19; i++){
      in1>>V>>a>>b>>c>>d;
      //cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr6->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }
   
   in2.open("driftScan_ROW_THGEM_20mbar-Ibeam150pA-2020-03-10.txt");
   in2.getline(buffer,200);
   //in2.getline(buffer,200);
   for(int i=0; i<10; i++){
      in2>>V>>a>>b>>c>>d;
      //cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr7->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }
 
   in3.open("driftScan_ROW_THGEM_20mbar-Ibeam60pA-2020-03-10.txt");
   in3.getline(buffer,200);
   for(int i=0; i<7; i++){
      in3>>V>>a>>b>>c>>d;
      //cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr8->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }
 
   in4.open("driftScan_ROW_THGEM_20mbar-Ibeam280pA-2020-03-10.txt");
   in4.getline(buffer,200);
   //in4.getline(buffer,200);
   for(int i=0; i<10; i++){
     in4>>V>>a>>b>>c>>d;
     // cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr9->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }



   in5.open("driftScan_ROW_THGEM_20mbar-Ibeam160pA-2020-03-10.txt");
   in5.getline(buffer,200);
   //in5.getline(buffer,200);
   for(int i=0; i<18; i++){
      in5>>V>>a>>b>>c>>d;
      //cout<<i<<"\t"<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;    
      gr10->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }


   in6.open("driftScan_ROW_THGEM_20mbar-twopoints-Ibeam280pA-2020-03-10.txt");
   in6.getline(buffer,200);
   for(int i=0; i<2; i++){
      in6>>V>>a>>b>>c>>d;
      //cout<<i<<"\t"<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;      
      gr11->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }

   in7.open("DriftScan_ROW_THGEM_20mbar.txt");
   in7.getline(buffer,200);
   for(int i=0; i<10; i++){
      in7>>V>>a>>b>>c>>d;
      //cout<<i<<"\t"<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;      
      gr12->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   } 
   
  TLegend *leg=new TLegend(0.8,0.6,0.98,0.96);
  leg->AddEntry(gr6,"R=3.4*10^{3}pps", "P");
  leg->AddEntry(gr11,"R=2.4*10^{3}pps", "P");
  leg->AddEntry(gr7,"R=1.3*10^{3}pps", "P");
  leg->AddEntry(gr8,"R=5.1*10^{2}pps", "P");
  leg->AddEntry(gr9,"R=2.2*10^{2}pps", "P");
  //leg->AddEntry(gr10,"R=1.3*10^{2}pps", "P");
  leg->AddEntry(gr12,"#alpha, V_{ind}=80V, V_{TH}=210V", "P");            
  
  TCanvas *c3a=new TCanvas("C3a");
  c3a->SetGrid();
  TH2F *bga=new TH2F("bga1","",1000,0,1300,1000,0,100);
   bga->SetStats(0);
   bga->GetXaxis()->SetTitle("V_{Drift} (V)");
   bga->GetXaxis()->SetTitleSize(0.05);
   bga->GetXaxis()->SetTitleOffset(0.85);
   bga->GetYaxis()->SetTitle("IBF (%)");
   bga->GetYaxis()->SetTitleSize(0.05);
   bga->GetYaxis()->SetTitleOffset(0.85);
   bga->Draw();
 
  gr6->SetTitle("IBF");
  gr6->SetMarkerStyle(20);
  gr6->SetMarkerSize(1);
  gr6->SetMarkerColor(kRed+1);
  gr6->SetLineWidth(1);
  gr6->SetLineColor(kRed+1);
  gr6->Draw("PL");
 
  gr7->SetTitle("ch6");
  gr7->SetMarkerStyle(20);
  gr7->SetMarkerSize(1);
  gr7->SetMarkerColor(kCyan-3);
  gr7->SetLineWidth(1);
  gr7->SetLineColor(kCyan-3);
  gr7->Draw("PL");
  
  gr8->SetTitle("ch6");
  gr8->SetMarkerStyle(20);
  gr8->SetMarkerSize(1);
  gr8->SetMarkerColor(kGreen +1);
  gr8->SetLineWidth(1);
  gr8->SetLineColor(kGreen +1);
  gr8->Draw("PL");
  
  gr9->SetTitle("ch6");
  gr9->SetMarkerStyle(20);
  gr9->SetMarkerSize(1);
  gr9->SetMarkerColor(kBlue +1);
  gr9->SetLineWidth(1);
  gr9->SetLineColor(kBlue +1);
  gr9->Draw("PL");

  gr10->SetTitle("ch6_bis");
  gr10->SetMarkerStyle(20);
  gr10->SetMarkerSize(1);
  gr10->SetMarkerColor(kBlue-1);
  gr10->SetLineWidth(1);
  gr10->SetLineColor(kBlue-1);
  //gr10->Draw("PL");


  gr11->SetTitle("ch6_tris");
  gr11->SetMarkerStyle(20);
  gr11->SetMarkerSize(1);
  gr11->SetMarkerColor(kOrange-3);
  gr11->SetLineWidth(1);
  gr11->SetLineColor(kOrange-3);
  gr11->Draw("P");

  gr12->SetTitle("ch6_tris");
  gr12->SetMarkerStyle(22);
  gr12->SetMarkerSize(1.3);
  gr12->SetMarkerColor(kAzure+7);
  gr12->SetLineWidth(1);
  gr12->SetLineColor(kAzure+7);
  gr12->Draw("PL");


  leg->Draw();  
}

