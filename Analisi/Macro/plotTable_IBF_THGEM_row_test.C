void plotTable_IBF_THGEM_row_test()
{
   double V, a, b, c, d;
   char buffer[200];
   
   TGraph *gr6=new TGraph(0);
   TGraph *gr7=new TGraph(0);
   TGraph *gr8=new TGraph(0);        
   TGraph *gr9=new TGraph(0);   
   TGraph *gr10=new TGraph(0);
   TGraph *gr11=new TGraph(0);

   ifstream in1, in2, in3, in4, in5, in6;
   in1.open("thgemScan_ROW_THGEM_20mbar.txt");
   in1.getline(buffer,200);
   for(int i=0; i<6; i++){
      in1>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<-d/(a+b)*100<<endl;
      
      gr6->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }
   cout<<"-----------------------"<<endl;

  
   in2.open("thgemScan_ROW_THGEM_20mbar-Ibeam400pA-2020-03-10.txt");
   in2.getline(buffer,200);
   for(int i=0; i<6; i++){
      in2>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<-d/(a+b)*100<<endl;  
      gr7->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }
   cout<<"-----------------------"<<endl;

   in3.open("thgemScan_ROW_THGEM_20mbar-Ibeam160pA-2020-03-10.txt");
   in3.getline(buffer,200);
   in3.getline(buffer,200);
   in3.getline(buffer,200);
   for(int i=0; i<6; i++){
      in3>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<-d/(a+b)*100<<endl;
      
      gr8->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }
   cout<<"-----------------------"<<endl;

   in4.open("driftScan_ROW_THGEM_20mbar-Ibeam280pA-2020-03-10.txt");
   for(int i=0; i<8; i++){
      in4.getline(buffer,200);
   }
      in4>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<-d/(a+b)*100<<endl;
      
      gr9->SetPoint(0, 190, -d/(a+b)*100);  	//anode + top3
   
   cout<<"-----------------------"<<endl;

 
   in5.open("driftScan_ROW_THGEM_20mbar-Ibeam150pA-2020-03-10.txt");
   for(int i=0; i<8; i++){
      in5.getline(buffer,200);
   }
      in5>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<-d/(a+b)*100<<endl;
      
      gr10->SetPoint(0, 190, -d/(a+b)*100);  	//anode + top3
   cout<<"-----------------------"<<endl;


   in6.open("driftScan_ROW_THGEM_20mbar-Ibeam60pA-2020-03-10.txt");
   for(int i=0; i<5; i++){
      in6.getline(buffer,200);
   }
      in6>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<-d/(a+b)*100<<endl;          
      gr11->SetPoint(0, 190, -d/(a+b)*100);  	//anode + top3
   
   cout<<"-----------------------"<<endl;

     
  TLegend *leg=new TLegend(0.1,0.7, 0.4,0.9);
  leg->AddEntry(gr6,"#alpha (R=140pps)", "P");
  leg->AddEntry(gr7,"R=3400pps", "P");
  //leg->AddEntry(gr10,"R=1300pps", "P");
  //leg->AddEntry(gr11,"R=510pps", "P");
  //leg->AddEntry(gr9,"R=220pps", "P");
  leg->AddEntry(gr8,"R~130pps", "P");

  TCanvas *c3a=new TCanvas("C3a");
  c3a->SetGrid();  
  TH2F *bga=new TH2F("bga1","",1000,160,250,1000,0,160);
   bga->SetStats(0);
   bga->GetXaxis()->SetTitle("V_{THGEM} (V)");
   bga->GetXaxis()->SetTitleSize(0.05);
   bga->GetXaxis()->SetTitleOffset(0.85);
   bga->GetYaxis()->SetTitle("IBF (%)");
   bga->GetYaxis()->SetTitleSize(0.05);
   bga->GetYaxis()->SetTitleOffset(0.85);
   bga->Draw();
 
  gr6->SetTitle("IBF");
  gr6->SetMarkerStyle(22);
  gr6->SetMarkerSize(1.3);
  gr6->SetMarkerColor(kAzure+7);
  gr6->SetLineWidth(1);
  gr6->SetLineColor(kAzure+7);
  gr6->Draw("PL");
 
  gr7->SetTitle("ch6");
  gr7->SetMarkerStyle(20);
  gr7->SetMarkerSize(1);
  gr7->SetMarkerColor(kRed+1);
  gr7->SetLineWidth(1);
  gr7->SetLineColor(kRed+1);
  gr7->Draw("PL");
  
  gr8->SetTitle("ch6");
  gr8->SetMarkerStyle(20);
  gr8->SetMarkerSize(1);
  gr8->SetMarkerColor(kBlue-1);
  gr8->SetLineWidth(1);
  gr8->SetLineColor(kBlue-1);
  gr8->Draw("PL");

  gr9->SetTitle("ch6");
  gr9->SetMarkerStyle(20);
  gr9->SetMarkerSize(1);
  gr9->SetMarkerColor(kBlue+1);
  gr9->SetLineWidth(1);
  gr9->SetLineColor(kBlue+1);
  //gr9->Draw("P");

  gr10->SetTitle("ch6");
  gr10->SetMarkerStyle(20);
  gr10->SetMarkerSize(1);
  gr10->SetMarkerColor(kCyan -3);
  gr10->SetLineWidth(1);
  gr10->SetLineColor(kCyan -3);
  //gr10->Draw("PL");

  gr11->SetTitle("ch6");
  gr11->SetMarkerStyle(20);
  gr11->SetMarkerSize(1);
  gr11->SetMarkerColor(kGreen+1);
  gr11->SetLineWidth(1);
  gr11->SetLineColor(kGreen+1);
  //gr11->Draw("PL"); 


  leg->Draw();  
}
