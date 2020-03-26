void plotTable_IBF_THGEM_beam()
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
   TGraph *gr13=new TGraph(0);
   TGraph *gr14=new TGraph(0);
   TGraph *gr15=new TGraph(0);

                
   
   ifstream in1, in2, in3, in4, in5, in6, in7, in8, in9, in10;
   in1.open("thgemScan_THGEM10_20mbar-Vdrift1000V-2020-03-09.txt");
   in1.getline(buffer,200);
      
   for(int i=0; i<11; i++){
      in1>>V>>a>>b>>c>>d;
      //cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr6->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }
   
   in2.open("thgemScan_THGEM10_20mbar_109pA-Vdrift1000V-2020-03-09.txt");
   in2.getline(buffer,200);

   for(int i=0; i<9; i++){
      in2>>V>>a>>b>>c>>d;
      //cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr7->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }
 
   in3.open("driftScan_THGEM10_20mbar_280pA-Vthgem205V-2020-03-09_onepoint.txt");
   in3.getline(buffer,200);

   for(int i=0; i<1; i++){
      in3>>V>>a>>b>>c>>d;
      //cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr8->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }
  
   in4.open("thgemScan_THGEM10_20mbar.txt");
   in4.getline(buffer,200);

   for(int i=0; i<9; i++){
     in4>>V>>a>>b>>c>>d;
     // cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr9->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }



   in5.open("driftScan_THGEM10_20mbar_60pA-Vthgem205V-2020-03-09_onepoint.txt");
   in5.getline(buffer,200);

   for(int i=0; i<1; i++){
      in5>>V>>a>>b>>c>>d;
      cout<<i<<"\t"<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;    
      gr10->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }


   in6.open("driftScan_THGEM10_20mbar_44pA-Vthgem205V-2020-03-09_onepoint.txt");
   in6.getline(buffer,200);

   for(int i=0; i<1; i++){
      in6>>V>>a>>b>>c>>d;
      cout<<i<<"\t"<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;      
      gr11->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }


   in7.open("driftScan_THGEM10_20mbar_300pA-Vthgem205V-2020-03-09_onepoint.txt");
   in7.getline(buffer,200);

   for(int i=0; i<1; i++){
      in7>>V>>a>>b>>c>>d;
      cout<<i<<"\t"<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<< -d/(a+b)*100<<endl;      
      gr12->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }

   in8.open("driftScan_THGEM10_20mbar_100pA-Vthgem205V-2020-03-09_onepoint.txt");
   in8.getline(buffer,200);

   for(int i=0; i<1; i++){
      in8>>V>>a>>b>>c>>d;
      cout<<i<<"\t"<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<< -d/(a+b)*100<<endl;      
      gr13->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }
/*
   in9.open("driftScan_THGEM10_1800pA_10mbar_onepoint_average.txt");

   for(int i=0; i<1; i++){
      in9>>V>>a>>b>>c>>d;
      cout<<i<<"\t"<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<< -d/(a+b)*100<<endl;      
      gr14->SetPoint(i, 150., -d/(a+b)*100);  	//anode + top3
   }

   in10.open("driftScan_THGEM10_1800pA_10mbar_onepoint_Vth160_average.txt");

   for(int i=0; i<1; i++){
      in10>>V>>a>>b>>c>>d;
      cout<<i<<"\t"<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<< -d/(a+b)*100<<endl;      
      gr15->SetPoint(i, 160., -d/(a+b)*100);  	//anode + top3
   }
   
*/   
  TLegend *leg=new TLegend(0.1,0.7, 0.5,1.0);
  leg->AddEntry(gr6,"3420 pps", "P");
  leg->AddEntry(gr7,"87 pps", "P");
  leg->AddEntry(gr8,"2400 pps", "P");
  leg->AddEntry(gr9,"#alpha", "P");
  leg->AddEntry(gr10,"514 pps", "P");
  leg->AddEntry(gr11,"35 pps", "P");
  leg->AddEntry(gr12,"241 pps", "P");
  leg->AddEntry(gr13,"856 pps", "P"); 
//  leg->AddEntry(gr14,"1.8 nA, V_{drift}=600V", "P");
//  leg->AddEntry(gr15,"1.8 nA, V_{drift}=600V", "P");
           
            

  
  TCanvas *c3a=new TCanvas("C3a");
  c3a->SetGrid();

  TH2F *bga=new TH2F("bga1","",1000,140,250,1000,0,100);
   bga->SetStats(0);
   bga->GetXaxis()->SetTitle("V_{THGEM} (V)");
   bga->GetXaxis()->SetTitleSize(0.05);
   bga->GetXaxis()->SetTitleOffset(0.90);
   bga->GetYaxis()->SetTitle("IBF (%)");
   bga->Draw();
 
  gr6->SetTitle("IBF");
  gr6->SetMarkerStyle(21);
  gr6->SetMarkerSize(1);
  gr6->SetMarkerColor(kOrange +10);
  gr6->SetLineWidth(1);
  gr6->SetLineColor(kOrange +10);
  gr6->Draw("PL");
 
  gr7->SetTitle("ch6");
  gr7->SetMarkerStyle(20);
  gr7->SetMarkerSize(1);
  gr7->SetMarkerColor(kGreen +2);
  gr7->SetLineWidth(1);
  gr7->SetLineColor(kGreen +2);
  gr7->Draw("PL");
  
  gr8->SetTitle("ch6");
  gr8->SetMarkerStyle(21);
  gr8->SetMarkerSize(1);
  gr8->SetMarkerColor(kMagenta +1);
  gr8->SetLineWidth(1);
  gr8->SetLineColor(kMagenta +1);
  gr8->Draw("PL");
  
  gr9->SetTitle("ch6");
  gr9->SetMarkerStyle(21);
  gr9->SetMarkerSize(1);
  gr9->SetMarkerColor(kOrange +5);
  gr9->SetLineWidth(1);
  gr9->SetLineColor(kOrange +5);
  gr9->Draw("PL");

  gr10->SetTitle("ch6_bis");
  gr10->SetMarkerStyle(21);
  gr10->SetMarkerSize(1.);
  gr10->SetMarkerColor(kBlue);
  gr10->SetLineWidth(1);
  gr10->SetLineColor(kBlue);
  gr10->Draw("PL");

  gr11->SetTitle("ch6_tris");
  gr11->SetMarkerStyle(20);
  gr11->SetMarkerSize(1);
  gr11->SetMarkerColor(kBlack);
  gr11->SetLineWidth(1);
  gr11->SetLineColor(kBlack);
  gr11->Draw("PL");

  gr12->SetTitle("ch6_tris");
  gr12->SetMarkerStyle(20);
  gr12->SetMarkerSize(1);
  gr12->SetMarkerColor(kRed +2);
  gr12->SetLineWidth(1);
  gr12->SetLineColor(kRed +2);
  gr12->Draw("PL");

  gr13->SetTitle("ch6_tris");
  gr13->SetMarkerStyle(21);
  gr13->SetMarkerSize(1);
  gr13->SetMarkerColor(kGreen +4);
  gr13->SetLineWidth(1);
  gr13->SetLineColor(kGreen +4);
  gr13->Draw("PL");
/*
  gr14->SetTitle("ch6_tris");
  gr14->SetMarkerStyle(20);
  gr14->SetMarkerSize(1);
  gr14->SetMarkerColor(kBlue);
  gr14->Draw("PL");

  gr15->SetTitle("ch6_tris");
  gr15->SetMarkerStyle(20);
  gr15->SetMarkerSize(1);
  gr15->SetMarkerColor(kRed +1);
  gr15->Draw("PL");
*/
  leg->Draw();  
}

