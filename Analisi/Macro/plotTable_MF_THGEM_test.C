void plotTable_MF_THGEM_test()
{
   double V, a, b, c, d;
   char buffer[200];
   
   // fattore di normalizzazione per la perdita di energia a seconda della pressione
   //Questi sono i valori per le alpha dell'241-Am
   //float fac1=2.33e-4;   // 10 mbar
   float fac2=4.72e-4;   // 20 mbar
   //float fac3=7.25e-4;   // 30 mbar
   //float fac4=9.97e-4;   // 40  mbar
   
   //Questo è il valore calcolato per l'18-O del test
   Float_t fac_test=1.4824e-3;
   
   TGraph *gr6=new TGraph(0);
   TGraph *gr7=new TGraph(0);
   TGraph *gr8=new TGraph(0);
   TGraph *gr9=new TGraph(0);  // Fino a qui i grafici per la FULL

   TGraph *gr10=new TGraph(0);
   TGraph *gr11=new TGraph(0);
   TGraph *gr12=new TGraph(0);
   TGraph *gr13=new TGraph(0);
   TGraph *gr14=new TGraph(0);
   TGraph *gr15=new TGraph(0);  // Fino a qui i grafici per la ROW
         
   ifstream in1, in2, in3, in4, in5;
   ifstream in6, in7, in8, in9, in10;

   in1.open("thgemScan_THGEM10_20mbar.txt");
   in1.getline(buffer,200);
      
   for(int i=0; i<9; i++){
      in1>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<-a/fac2<<endl;
      
      gr6->SetPoint(i, V, -a/fac2);      //anode + top3
   }
   
   cout << "-------------------" << endl;

   in2.open("thgemScan_THGEM10_20mbar-Vdrift1000V-2020-03-09.txt");
   in2.getline(buffer,200);

   for(int i=0; i<11; i++){
      in2>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<-a/fac_test<<endl;
      
      gr7->SetPoint(i, V, -a/fac_test);      //anode + top3
   }
 
   cout << "-------------------" << endl;


   in3.open("thgemScan_THGEM10_20mbar_109pA-Vdrift1000V-2020-03-09.txt");
   in3.getline(buffer,200);

   for(int i=0; i<9; i++){
      in3>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<-a/fac_test<<endl;
      
      gr8->SetPoint(i, V, -a/fac_test);      //anode + top3
   }


   cout << "-------------------" << endl;

/*
   in4.open("thgemScan_THGEM10_10mbar_bis.txt");
   in4.getline(buffer,200);
   for(int i=0; i<9; i++){
      in4>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr9->SetPoint(i, V, -a/fac1);      //anode + top3
   }
 
   in5.open("thgemScan_ROW_THGEM_20mbar.txt");  // Vdrift=800V
   in5.getline(buffer,200);
   in5.getline(buffer,200);
 
   for(int i=0; i<4; i++){
      in5>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr10->SetPoint(i, V, -a/fac2);      //anode + top3
   }
 
   in6.open("thgemScan_ROW_THGEM_30mbar.txt");  // Vdrift=800V
   in6.getline(buffer,200);
 
   for(int i=0; i<8; i++){
      in6>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr11->SetPoint(i, V, -a/fac3);      //anode + top3
   }
   
   in7.open("thgemScan_ROW_THGEM_40mbar.txt");
   in7.getline(buffer,200);
 
   for(int i=0; i<8; i++){
      in7>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr12->SetPoint(i, V, -a/fac4);      //anode + top3
   }
   
   in8.open("thgemScan_ROW_THGEM_30mbar_bis.txt");  // Vdrift=400V
   in8.getline(buffer,200);
 
   for(int i=0; i<13; i++){
      in8>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr13->SetPoint(i, V, -a/fac3);      //anode + top3
   }
   
   
   in9.open("thgemScan_ROW_THGEM_20mbar_bis.txt");  // Vdrift=300V
   in9.getline(buffer,200);
   in9.getline(buffer,200);
   in9.getline(buffer,200);
   in9.getline(buffer,200);
   in9.getline(buffer,200);
 
   for(int i=0; i<14; i++){
      in9>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr14->SetPoint(i, V, -a/fac2);      //anode + top3
   }
   in10.open("thgemScan_ROW_THGEM_10mbar.txt");
   in10.getline(buffer,200);
 
   for(int i=0; i<11; i++){
      in10>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr15->SetPoint(i, V, -a/fac1);      //anode + top3
   }
*/
   
  TLegend *leg=new TLegend(0.1,0.6, 0.4,0.9);
  leg->AddEntry(gr6,"#alpha", "P");
  leg->AddEntry(gr7,"R=3200 pps", "P");
  leg->AddEntry(gr8,"R=87 pps", "P");
  //leg->AddEntry(gr7,"FULL, 30 mbar", "P");
  //leg->AddEntry(gr15,"ROW, 10 mbar", "P");
  //leg->AddEntry(gr10,"ROW, 20 mbar, V_{drift}=800V", "P");
  //leg->AddEntry(gr14,"ROW, 20 mbar, V_{drift}=300V", "P");
  //leg->AddEntry(gr11,"ROW, 30 mbar, V_{drift}=800V", "P");
  //leg->AddEntry(gr13,"ROW, 30 mbar, V_{drift}=400V", "P");
  //leg->AddEntry(gr12,"ROW, 40 mbar", "P");
  
  TCanvas *c3a=new TCanvas("C3a");
  c3a->SetGrid();
  //c3a->SetLogy();
  
  TH2F *bga=new TH2F("bga1","",1000,130.,240.,1000,0.,500000000000.);
   bga->SetStats(0);
   bga->GetXaxis()->SetTitle("V_{THGEM} (V)");
   bga->GetXaxis()->SetTitleSize(0.05);
   bga->GetXaxis()->SetTitleOffset(0.85);
   bga->GetYaxis()->SetTitle("Multiplication Factor");
   bga->GetYaxis()->SetTitleSize(0.05);
   bga->GetYaxis()->SetTitleOffset(0.85);
   //bga->Draw();
 
  gr6->SetTitle("");
  gr6->GetXaxis()->SetTitle("V_{THGEM} (V)");
  gr6->GetXaxis()->SetTitleSize(0.05);
  gr6->GetXaxis()->SetTitleOffset(0.85);
  gr6->GetYaxis()->SetTitle("Multiplication Factor");
  gr6->GetYaxis()->SetTitleSize(0.05);
  gr6->GetYaxis()->SetTitleOffset(0.85);
  gr6->SetMarkerStyle(22);
  gr6->SetMarkerSize(1.3);
  gr6->SetMarkerColor(kAzure+7);
  gr6->SetLineWidth(1);
  gr6->SetLineColor(kAzure+7);
//  gr6->GetYaxis()->SetRangeUser(0., 100000.);
//  auto Xaxis = gr6->GetXaxis();
//  Xaxis->SetLimits(140., 260.);
  gr6->GetHistogram()->SetMinimum(1.);
  gr6->Draw("APL");
  
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
/* 
  gr9->SetTitle("ch6");
  gr9->SetMarkerStyle(20);
  gr9->SetMarkerSize(1);
  gr9->SetMarkerColor(kOrange -2);
  gr9->SetLineWidth(1);
  gr9->SetLineColor(kOrange -2);
  //gr9->Draw("PL");

  // Fino a qui per la FULL
   
  gr10->SetTitle("ch6");
  gr10->SetMarkerStyle(21);
  gr10->SetMarkerSize(1);
  gr10->SetMarkerColor(kOrange +3);
  gr10->SetLineWidth(1);
  gr10->SetLineColor(kOrange +3);
  //gr10->Draw("PL");
  
  gr11->SetTitle("ch6");
  gr11->SetMarkerStyle(21);
  gr11->SetMarkerSize(1);
  gr11->SetMarkerColor(kGreen +3);
  gr11->SetLineWidth(1);
  gr11->SetLineColor(kGreen +3);
  //gr11->Draw("PL");
  
  gr12->SetTitle("ch6");
  gr12->SetMarkerStyle(21);
  gr12->SetMarkerSize(1);
  gr12->SetMarkerColor(kGreen -5);
  gr12->SetLineWidth(1);
  gr12->SetLineColor(kGreen -5);
  //gr12->Draw("PL");
  
  gr13->SetTitle("ch6");
  gr13->SetMarkerStyle(21);
  gr13->SetMarkerSize(1);
  gr13->SetMarkerColor(kGreen +1);
  gr13->SetLineWidth(1);
  gr13->SetLineColor(kGreen +1);
  //gr13->Draw("PL");
  
  gr14->SetTitle("ch6");
  gr14->SetMarkerStyle(21);
  gr14->SetMarkerSize(1);
  gr14->SetMarkerColor(kOrange -1);
  gr14->SetLineWidth(1);
  gr14->SetLineColor(kOrange -1);
  //gr14->Draw("PL");
  
  gr15->SetTitle("ch6");
  gr15->SetMarkerStyle(21);
  gr15->SetMarkerSize(1);
  gr15->SetMarkerColor(kOrange +5);
  gr15->SetLineWidth(1);
  gr15->SetLineColor(kOrange +5);
  //gr15->Draw("PL");
*/
  leg->Draw();
}
