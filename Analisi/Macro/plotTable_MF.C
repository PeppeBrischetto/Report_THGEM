void plotTable(char* filename)
{
   double V, a, b, c, d;
   char buffer[200];
   
   ifstream in;
   in.open(filename);
   
   in.getline(buffer,200);
   
   TGraph *gr1=new TGraph(0);
   TGraph *gr2=new TGraph(0);
   TGraph *gr3=new TGraph(0);
   TGraph *gr4=new TGraph(0); 
   
   TGraph *gr5=new TGraph(0); 
   
   for(int i=0; i<22; i++){
      in>>V>>a>>b>>c>>d;
      cout<<V<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr1->SetPoint(i, V, a); 
      gr2->SetPoint(i, V, b); 
      gr3->SetPoint(i, V, c); 
      gr4->SetPoint(i, V, d);
      
      //gr5->SetPoint(i, V, c+d);  //cathode + bot1
      gr5->SetPoint(i, V, a+b);  	//anode + top3
   }

   
  gr1->SetTitle("ch1");
  gr1->SetMarkerStyle(20);
  gr1->SetMarkerSize(1);
  gr1->SetMarkerColor(kBlue);
  gr1->SetLineWidth(1);
  gr1->SetLineColor(kBlue);
  gr2->SetTitle("ch2");
  gr2->SetMarkerStyle(20);
  gr2->SetMarkerSize(1);
  gr2->SetMarkerColor(kOrange);  
  gr2->SetLineWidth(1);
  gr2->SetLineColor(kOrange);
  gr3->SetTitle("ch5");
  gr3->SetMarkerStyle(20);
  gr3->SetMarkerSize(1);
  gr3->SetMarkerColor(kGray +2);
  gr3->SetLineWidth(1);
  gr3->SetLineColor(kGray +2);  
  gr4->SetTitle("ch6");
   gr4->SetMarkerStyle(20);
   gr4->SetMarkerSize(1);
   gr4->SetMarkerColor(kOrange +3);
   gr4->SetLineWidth(1);
   gr4->SetLineColor(kOrange +3);

   gr5->SetTitle("ch6");
   gr5->SetMarkerStyle(20);
   gr5->SetMarkerSize(1);
   gr5->SetMarkerColor(kOrange +5);
   gr5->SetLineWidth(1);
   gr5->SetLineColor(kOrange +5);

   TCanvas *c2a=new TCanvas("C2a");  
   TH2F *bga=new TH2F("bga","",1000,0,200,1000,-15,25);
   bga->SetStats(0);
   bga->GetXaxis()->SetTitle("V_{ind} (V)");
   bga->GetYaxis()->SetTitle("I (nA)");
   bga->Draw();
   gr1->Draw("PL ");
   gr2->Draw("PL");
   gr3->Draw("PL");
   gr4->Draw("PL");
   gr5->Draw("PL");
   
  TLegend *leg=new TLegend(0.1,0.7, 0.4,0.9);
  leg->AddEntry(gr1,"anode", "P");
  leg->AddEntry(gr2,"top3", "P");
  leg->AddEntry(gr3,"bot1", "P");
  leg->AddEntry(gr4,"cathode", "P");
  //leg->AddEntry(gr5,"sum cathode+bot1", "P");
  leg->AddEntry(gr5,"sum anode+top3", "P");
   
  leg->Draw();
  
  TLine *zero=new TLine(170,0,250,0);
  zero->SetLineStyle(2);
  zero->Draw();
}
