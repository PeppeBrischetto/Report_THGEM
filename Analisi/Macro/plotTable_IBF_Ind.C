void plotTable_IBF_Ind()
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
   in1.open("InductionScan_THGEM10_10mbar.txt");
   in1.getline(buffer,200);
      
   for(int i=0; i<7; i++){
      in1>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr6->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }
   
   in2.open("InductionScan_THGEM10_20mbar.txt");
   in2.getline(buffer,200);

   for(int i=0; i<22; i++){
      in2>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr7->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }
 
   in3.open("InductionScan_THGEM10_30mbar.txt");
   in3.getline(buffer,200);

   for(int i=0; i<24; i++){
      in3>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr8->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }
 
   in4.open("InductionScan_ROW_THGEM_20mbar.txt");
   in4.getline(buffer,200);

   for(int i=0; i<12; i++){
      in4>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr9->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }


   in5.open("InductionScan_ROW_THGEM_30mbar.txt");
   in5.getline(buffer,200);

   for(int i=0; i<12; i++){
      in5>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr10->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }

  in6.open("InductionScan_ROW_THGEM_40mbar.txt");
  in6.getline(buffer,200);

   for(int i=0; i<16; i++){
      in6>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr11->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }

 
   
  TLegend *leg=new TLegend(0.1,0.7, 0.4,0.9);
  leg->AddEntry(gr6,"Full 10 mbar", "P");
  leg->AddEntry(gr7,"Full 20 mbar", "P");
  leg->AddEntry(gr8,"Full 30 mbar", "P");
  leg->AddEntry(gr9,"Row 20 mbar", "P");
  leg->AddEntry(gr10,"Row 30 mbar", "P");
  leg->AddEntry(gr11,"Row 40 mbar", "P");            
  
  TCanvas *c3a=new TCanvas("C3a");  
  TH2F *bga=new TH2F("bga1","",1000,0,220,1000,0,110);
   bga->SetStats(0);
   bga->GetXaxis()->SetTitle("V_{ind} (V)");
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
  
  gr9->SetTitle("ch6");
  gr9->SetMarkerStyle(21);
  gr9->SetMarkerSize(1);
  gr9->SetMarkerColor(kBlue +3);
  gr9->SetLineWidth(1);
  gr9->SetLineColor(kBlue +3);
  gr9->Draw("PL");

  gr10->SetTitle("ch6");
  gr10->SetMarkerStyle(21);
  gr10->SetMarkerSize(1);
  gr10->SetMarkerColor(kBlue -3);
  gr10->SetLineWidth(1);
  gr10->SetLineColor(kBlue -3);
  gr10->Draw("PL");

  gr11->SetTitle("ch6");
  gr11->SetMarkerStyle(21);
  gr11->SetMarkerSize(1);
  gr11->SetMarkerColor(kBlue -1);
  gr11->SetLineWidth(1);
  gr11->SetLineColor(kBlue -1);
  gr11->Draw("PL");


  leg->Draw();  
}

