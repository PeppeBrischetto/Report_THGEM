//  Macro per visualizzare le correnti anode, top3, ecc. in funzione del rate di particelle incidenti
// 05/04/20: Aggiunta una barra di errore del 10% al rate (quindi i TGraph sono diventati TGraphErrors)


void plotTable_Rate(char* filename)
{
   double R, a, b, c, d;
   char buffer[200];
   
   ifstream in;
   in.open(filename);
   
   in.getline(buffer,200);
   
   TGraphErrors *gr1=new TGraphErrors(0);
   TGraphErrors *gr2=new TGraphErrors(0);
   TGraphErrors *gr3=new TGraphErrors(0);
   TGraphErrors *gr4=new TGraphErrors(0); 
   
   TGraphErrors *gr5=new TGraphErrors(0); 
   
   for(int i=0; i<6; i++){
      in>>R>>a>>b>>c>>d;
      cout<<R<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl;
      
      gr1->SetPoint(i, R, a); 
      gr2->SetPoint(i, R, b); 
      gr3->SetPoint(i, R, c); 
      gr4->SetPoint(i, R, d);
      
      //gr5->SetPoint(i, R, c+d);  //cathode + bot1
      gr5->SetPoint(i, R, a+b);  	//anode + top3

      gr1->SetPointError(i, 0.1*R, 0.); 
      //gr2->SetPointError(i, R, b); 
      //gr3->SetPointError(i, R, c); 
      //gr4->SetPointError(i, R, d);
      
      //gr5->SetPointError(i, R, c+d);  //cathode + bot1
      //gr5->SetPointError(i, R, a+b);  	//anode + top3


/*      
      gr1->SetPoint(i, R, TMath::Abs(a*1000)); 
      gr2->SetPoint(i, R, TMath::Abs(b*1000)); 
      gr3->SetPoint(i, R, TMath::Abs(c*1000)); 
      gr4->SetPoint(i, R, TMath::Abs(d*1000));
      
      //gr5->SetPoint(i, R, c+d);  //cathode + bot1
      gr5->SetPoint(i, R, TMath::Abs(a+b)*1000);  //anode + top3 
*/
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
   c2a->SetGrid();
   //c2a->SetLogy();  
   TH2F *bga=new TH2F("bga","",1000,0,4000,500,-10.,1.);
   bga->SetStats(0);
   bga->GetXaxis()->SetTitle("Rate (pps)");
   bga->GetXaxis()->SetTitleSize(0.05);
   bga->GetXaxis()->SetTitleOffset(0.85);
   bga->GetYaxis()->SetTitle("I (nA)");
   bga->GetYaxis()->SetTitleSize(0.05);
   bga->GetYaxis()->SetTitleOffset(0.85);
   bga->Draw();

   gr1->Draw("PL ");
   //gr2->Draw("PL");
   //gr3->Draw("PL");
   //gr4->Draw("PL");
   //gr5->Draw("PL");
   
  TLegend *leg=new TLegend(0.1,0.7, 0.4,0.9);
  leg->AddEntry(gr1,"anode", "PL");
  //leg->AddEntry(gr2,"top3", "P");
  //leg->AddEntry(gr3,"bot1", "P");
  //leg->AddEntry(gr4,"cathode", "P");
  //leg->AddEntry(gr5,"sum cathode+bot1", "P");
  //leg->AddEntry(gr5,"sum anode+top3", "P");
   
  leg->Draw();
  
   tex = new TLatex(1000,.5,"V_{drift}=400V");
   //tex = new TLatex(1000,.5,"V_{drift}=1000V");
   tex->SetLineWidth(2);
   tex->Draw();


  TLine *zero=new TLine(170,0,250,0);
  zero->SetLineStyle(2);
  //zero->Draw();
}
