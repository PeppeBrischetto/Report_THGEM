void plotTable_IBF_Ibeam()
{
   double I, a, b, c, d;
   char buffer[200];
   
   TGraph *gr6=new TGraph(0);
   TGraph *gr7=new TGraph(0);
   TGraph *gr8=new TGraph(0);
   TGraph *gr9=new TGraph(0);
   TGraph *gr10=new TGraph(0);
   TGraph *gr11=new TGraph(0);
   TGraph *gr12=new TGraph(0);
                
   
   ifstream in1, in2, in3, in4, in5, in6, in7;
   in1.open("IbeamScan_THGEM10_10mbar_average.txt");
   in1.getline(buffer,200);
      
   for(int i=0; i<4; i++){
      in1>>I>>a>>b>>c>>d;
      //cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr6->SetPoint(i, I, -d/(a+b)*100);  	//anode + top3
   }

   // La parte di codice successiva è commentata perché presa dalla macro per plottare l'IBF in funzione della Vdrift. Probabilmente questa parte si può eliminare ma per adesso la teniamo.
/*
   in2.open("driftScan_THGEM10_20mbar.txt");
   in2.getline(buffer,200);

   for(int i=0; i<15; i++){
      in2>>V>>a>>b>>c>>d;
      //cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr7->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }
 
   in3.open("driftScan_THGEM10_30mbar.txt");
   in3.getline(buffer,200);

   for(int i=0; i<20; i++){
      in3>>V>>a>>b>>c>>d;
      //cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr8->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }
   
   in4.open("DriftScan_ROW_THGEM_30mbar.txt");
   in4.getline(buffer,200);
   in4.getline(buffer,200);

   for(int i=0; i<13; i++){
     in4>>V>>a>>b>>c>>d;
     // cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr9->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }



   in5.open("DriftScan_ROW_THGEM_30mbar_bis.txt");
   in5.getline(buffer,200);
   in5.getline(buffer,200);

   for(int i=0; i<13; i++){
      in5>>V>>a>>b>>c>>d;
      cout<<i<<"\t"<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;    
      gr10->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }


   in6.open("DriftScan_ROW_THGEM_20mbar.txt");
   in6.getline(buffer,200);

   for(int i=0; i<10; i++){
      in6>>V>>a>>b>>c>>d;
      cout<<i<<"\t"<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;      
      gr11->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }


   in7.open("DriftScan_ROW_THGEM_10mbar.txt");
   in7.getline(buffer,200);
   in7.getline(buffer,200);

   for(int i=0; i<16; i++){
      in7>>V>>a>>b>>c>>d;
      cout<<i<<"\t"<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<< -d/(a+b)*100<<endl;      
      gr12->SetPoint(i, V, -d/(a+b)*100);  	//anode + top3
   }
*/   
   
  TLegend *leg=new TLegend(0.1,0.7, 0.5,1.0);
  leg->AddEntry(gr6,"FULL 10 mbar", "P");
  //leg->AddEntry(gr7,"FULL 20 mbar", "P");
  //leg->AddEntry(gr8,"FULL 30 mbar", "P");
  //leg->AddEntry(gr12,"ROW 10 mbar", "P");
  //leg->AddEntry(gr11,"ROW 20 mbar", "P"); 
  //leg->AddEntry(gr9,"ROW 30 mbar, V_{THGEM} 240V", "P");
  //leg->AddEntry(gr9,"ROW 30 mbar", "P");
  //leg->AddEntry(gr10,"ROW 30 mbar, V_{THGEM} 230V", "P");
           
            

  
  TCanvas *c3a=new TCanvas("C3a");
  c3a->SetGrid();

  TH2F *bga=new TH2F("bga1","",1000,0,2000,1000,0,110);
   bga->SetStats(0);
   bga->GetXaxis()->SetTitle("I_{beam} (pA)");
   bga->GetXaxis()->SetTitleSize(0.05);
   bga->GetXaxis()->SetTitleOffset(0.90);
   bga->GetYaxis()->SetTitle("IBF (%)");
   bga->GetYaxis()->SetTitleSize(0.05);
   bga->GetYaxis()->SetTitleOffset(0.85);
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
  //gr7->Draw("PL");
  
  gr8->SetTitle("ch6");
  gr8->SetMarkerStyle(20);
  gr8->SetMarkerSize(1);
  gr8->SetMarkerColor(kGreen +3);
  gr8->SetLineWidth(1);
  gr8->SetLineColor(kGreen +3);
  //gr8->Draw("PL");
  
  gr9->SetTitle("ch6");
  gr9->SetMarkerStyle(21);
  gr9->SetMarkerSize(1);
  gr9->SetMarkerColor(kGreen +3);
  gr9->SetLineWidth(1);
  gr9->SetLineColor(kGreen +3);
  //gr9->Draw("PL");

  gr10->SetTitle("ch6_bis");
  gr10->SetMarkerStyle(21);
  gr10->SetMarkerSize(1.);
  gr10->SetMarkerColor(kGreen+1);
  gr10->SetLineWidth(1);
  gr10->SetLineColor(kGreen+1);
  //gr10->Draw("PL");

  gr11->SetTitle("ch6_tris");
  gr11->SetMarkerStyle(21);
  gr11->SetMarkerSize(1);
  gr11->SetMarkerColor(kOrange+3);
  gr11->SetLineWidth(1);
  gr11->SetLineColor(kOrange+3);
  //gr11->Draw("PL");

  gr12->SetTitle("ch6_tris");
  gr12->SetMarkerStyle(21);
  gr12->SetMarkerSize(1);
  gr12->SetMarkerColor(kOrange+5);
  gr12->SetLineWidth(1);
  gr12->SetLineColor(kOrange+5);
  //gr12->Draw("PL");

  leg->Draw();  
}

