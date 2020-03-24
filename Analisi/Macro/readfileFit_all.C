void readfileFit_all(char *filename)
{
   gStyle->SetTitleSize(0.1,"t");
  // gStyle->SetTitleOffset(14,"t");

  int d=5e3;
  int a=60e3;
  int b=90e3;
  int c=150e3;

  float I0, I1, I2, I3, I4, I5, I6, V0, V1, V2, V3, V4, V5, V6;
  int time, timeold, timeRef;
  int run, n, lnum=0;
  char *buffer=new char[200];
  //char c;
  
  ifstream in;
  //in.open("Sorgente_off_on_off.txt");
  in.open(filename);
  in>>timeRef;
  cout<<"timeRef: "<<timeRef<<endl;
  
  // conta il numero di linee del file
  while(in>>time){
    //in>>time;
    //cout<<"*"<<time<<endl;
    in>>V0>>V1>>V2>>V3>>V4>>V5>>V6;
    //cout<<V0<<"\t"<<V1<<"\t"<<V2<<"\t"<<V3<<"\t"<<V4<<"\t"<<V5<<"\t"<<V6<<endl;
    in>>I0>>I1>>I2>>I3>>I4>>I5>>I6;
    //cout<<I0<<"\t"<<I1<<"\t"<<I2<<"\t"<<I3<<"\t"<<I4<<"\t"<<I5<<"\t"<<I6<<endl;
    lnum++;
    //cout<<" |"<<lnum<<endl;
  }
  cout<<"number of entries: "<<lnum<<endl;
  
  in.close();
  //in.open("Sorgente_off_on_off.txt");
  in.open(filename);
  

  TGraph *gr1=new TGraph(0);
  TGraph *gr2=new TGraph(0);
  TGraph *gr3=new TGraph(0);
  TGraph *gr4=new TGraph(0);
  TGraph *gr5=new TGraph(0);
  TGraph *gr6=new TGraph(0);

  TGraph *gr1a=new TGraph(0);
  TGraph *gr2a=new TGraph(0);
  TGraph *gr3a=new TGraph(0);
  TGraph *gr4a=new TGraph(0);
  TGraph *gr5a=new TGraph(0);
  TGraph *gr6a=new TGraph(0);

  int n=0,na=0;
  int A=1;
  float I0a=0, I1a=0, I2a=0, I3a=0, I4a=0, I5a=0, I6a=0;
  timeold=0;
  int timeRed;
  float DeltaT;
  
  float max[7]={0};
  float min[7]={100000};
  
  
  for(int i=0; i<lnum; i++){
    in>>time;
    in>>V0>>V1>>V2>>V3>>V4>>V5>>V6;
    in>>I0>>I1>>I2>>I3>>I4>>I5>>V6;
    //cout<<n<<" "<<I0<<"\t"<<I1<<"\t"<<I2<<"\t"<<I3<<"\t"<<I4<<"\t"<<I5<<"\t"<<I6<<endl;
    if(I0>max[0]) max[0]=I0;
    if(I1>max[1]) max[1]=I1;
    if(I2>max[2]) max[2]=I2;
    if(I3>max[3]) max[3]=I3;
    if(I4>max[4]) max[4]=I4;
    if(I5>max[5]) max[5]=I5;
    if(I6>max[6]) max[6]=I6;
    
    if(I0<min[0]) min[0]=I0;
    if(I1<min[1]) min[1]=I1;
    if(I2<min[2]) min[2]=I2;
    if(I3<min[3]) min[3]=I3;
    if(I4<min[4]) min[4]=I4;
    if(I5<min[5]) min[5]=I5;
    if(I6<min[6]) min[6]=I6;
    
    timeRed=time/1000;
  
  
    gr1->SetPoint(n, (time-timeRef), -I0*1000); 
    gr2->SetPoint(n, (time-timeRef), -I1*1000); 
    gr3->SetPoint(n, (time-timeRef), -I2*1000); 
    gr4->SetPoint(n, (time-timeRef), -I3*1000); 
    gr5->SetPoint(n, (time-timeRef), -I4*1000); 
    gr6->SetPoint(n++, (time-timeRef), -I5*1000);     
   
    //if(run>=14063 && run<=14069){gr5->SetPoint(n++, Vind, -I0); }
    if((time-timeRef)<-200000)
    {cout<<"ffff"<<time<<endl;
    cout<<"ffff"<<timeRef<<endl;
    }
  } 
  DeltaT=time-timeRef;
  cout<<"DT: "<<DeltaT<<endl;
  for(i =0; i<7; i++) 
  {cout<<min[i]<<"\t"<<max[i]<<endl;}
   
   
  /*TCanvas *c1=new TCanvas("C1");
  TH2F *bg=new TH2F("bg","",1000,0,DeltaT,1000,-0.005,0.005);
  bg->SetStats(0);
  bg->Draw();
  gr1->SetMarkerStyle(20);
  gr1->SetMarkerSize(1);
  gr1->SetMarkerColor(kBlue);
  gr2->SetMarkerStyle(20);
  gr2->SetMarkerSize(1);
  gr2->SetMarkerColor(kOrange);
  gr3->SetMarkerStyle(20);
  gr3->SetMarkerSize(1);
  gr3->SetMarkerColor(kGreen -3);
  gr4->SetMarkerStyle(20);
  gr4->SetMarkerSize(1);
  gr4->SetMarkerColor(kCyan +1);
  gr5->SetMarkerStyle(20);
  gr5->SetMarkerSize(1);
  gr5->SetMarkerColor(kGray +2);
  gr6->SetMarkerStyle(20);
  gr6->SetMarkerSize(1);
  gr6->SetMarkerColor(kOrange +3);

  gr1->Draw("P");
  gr2->Draw("P");
 // gr3->Draw("P");
 // gr4->Draw("P");
  gr5->Draw("P");
  gr6->Draw("P");

  /*TCanvas *c1a=new TCanvas("C1a");
  TH2F *bga=new TH2F("bga","",1000,0,500,1000,-0.005,0.005);
  bga->SetStats(0);
  bga->Draw();
  gr1a->SetTitle("Anodo");
  
  gr1a->SetMarkerStyle(20);
  gr1a->SetMarkerSize(1);
  gr1a->SetMarkerColor(kBlue);
  gr1a->SetLineWidth(1);
  gr1a->SetLineColor(kBlue);
  gr2a->SetTitle("Top 3");
  gr2a->SetMarkerStyle(20);
  gr2a->SetMarkerSize(1);
  gr2a->SetMarkerColor(kOrange);
  gr3a->SetMarkerStyle(20);
  gr3a->SetMarkerSize(1);
  gr3a->SetMarkerColor(kGreen -3);
  gr4a->SetMarkerStyle(20);
  gr4a->SetMarkerSize(1);
  gr4a->SetMarkerColor(kCyan +1);
  gr5a->SetTitle("Bot 1");
  gr5a->SetMarkerStyle(20);
  gr5a->SetMarkerSize(1);
  gr5a->SetMarkerColor(kGray +2);
  gr6a->SetTitle("Cathode");
  gr6a->SetMarkerStyle(20);
  gr6a->SetMarkerSize(1);
  gr6a->SetMarkerColor(kOrange +3);

  gr1a->Draw("PL");
  gr2a->Draw("PL");
  //gr3a->Draw("PL");
  //gr4a->Draw("PL");
  gr5a->Draw("PL");
  gr6a->Draw("PL");*/

  TFitResultPtr pr1;
  TFitResultPtr pr2;
  TFitResultPtr pr3;
  TFitResultPtr pr4;
  TFitResultPtr pr5;
  TFitResultPtr pr6;
  TFitResultPtr pr1b;
  TFitResultPtr pr2b;
  TFitResultPtr pr3b;
  TFitResultPtr pr4b;
  TFitResultPtr pr5b;
  TFitResultPtr pr6b;

  TF1 *const1=new TF1("const1","[0]",d,a);
  TF1 *const1b=new TF1("const1b","[0]",b,c);
  TF1 *const2=new TF1("const2","[0]",d,a);
  TF1 *const2b=new TF1("const2b","[0]",b,c);
  TF1 *const3=new TF1("const3","[0]",d,a);
  TF1 *const3b=new TF1("const3b","[0]",b,c);
  TF1 *const4=new TF1("const4","[0]",d,a);
  TF1 *const4b=new TF1("const4b","[0]",b,c);
  TF1 *const5=new TF1("const5","[0]",d,a);
  TF1 *const5b=new TF1("const5b","[0]",b,c);
  TF1 *const6=new TF1("const6","[0]",d,a);
  TF1 *const6b=new TF1("const6b","[0]",b,c);
  
 // const1->SetLineColor(kGreen +2);
 // const1->SetLineWidth(6);



  //bga->SetStats(0);
  TCanvas *c2a=new TCanvas("C2a");
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
  gr3->SetTitle("ch3");
  gr3->SetMarkerStyle(20);
  gr3->SetMarkerSize(1);
  gr3->SetMarkerColor(kGreen -3);
  gr3->SetLineWidth(1);
  gr3->SetLineColor(kGreen -3);
  gr4->SetTitle("ch4");
  gr4->SetMarkerStyle(20);
  gr4->SetMarkerSize(1);
  gr4->SetMarkerColor(kCyan +1);
  gr4->SetLineWidth(1);
  gr4->SetLineColor(kCyan +1);
  gr5->SetTitle("ch5");
  gr5->SetMarkerStyle(20);
  gr5->SetMarkerSize(1);
  gr5->SetMarkerColor(kGray +2);
  gr5->SetLineWidth(1);
  gr5->SetLineColor(kGray +2);  
  gr6->SetTitle("ch6");
  gr6->SetMarkerStyle(20);
  gr6->SetMarkerSize(1);
  gr6->SetMarkerColor(kOrange +3);
  gr6->SetLineWidth(1);
  gr6->SetLineColor(kOrange +3);
  
  
  c2a->Divide(1,6);
  c2a->cd(1);
  gr1->GetXaxis()->SetTitle("time (msec)");
  gr1->GetYaxis()->SetTitle("current (nA)");
  gr1->GetYaxis()->SetTitleOffset(1.25);
  
  gr1->GetXaxis()->SetTitleOffset(0.4);
  gr1->GetXaxis()->SetLabelSize(0.09);
  gr1->GetXaxis()->SetTitleSize(0.09);
  gr1->GetYaxis()->SetTitleOffset(0.4);
  gr1->GetYaxis()->SetLabelSize(0.09);
  gr1->GetYaxis()->SetTitleSize(0.09);
  gr1->Draw("APL");
 // gr1->GetXaxis()->SetRangeUser(0,250000);
  pr1=gr1->Fit("const1","S0","",d,a);
  const1->Draw("same");
  pr1b=gr1->Fit("const1b","S0","",b,c);
  const1b->Draw("same");
     
  c2a->cd(2);
  gr2->GetXaxis()->SetTitle("time (msec)");
  gr2->GetYaxis()->SetTitle("current (nA)");
  gr2->GetYaxis()->SetTitleOffset(1.25);
  gr2->GetXaxis()->SetTitleOffset(0.4);
  gr2->GetXaxis()->SetLabelSize(0.09);
  gr2->GetXaxis()->SetTitleSize(0.09);
  gr2->GetYaxis()->SetTitleOffset(0.4);
  gr2->GetYaxis()->SetLabelSize(0.09);
  gr2->GetYaxis()->SetTitleSize(0.09);
  gr2->Draw("APL");
  pr2=gr2->Fit("const2","S","",d,a);
  const2->Draw("SAME");
  pr2b=gr2->Fit("const2b","S","",b,c);
  const2b->Draw("SAME");

  c2a->cd(3);
  gr3->GetXaxis()->SetTitle("time (msec)");
  gr3->GetYaxis()->SetTitle("current (nA)");
  gr3->GetYaxis()->SetTitleOffset(1.25);
  gr3->GetXaxis()->SetTitleOffset(0.4);
  gr3->GetXaxis()->SetLabelSize(0.09);
  gr3->GetXaxis()->SetTitleSize(0.09);
  gr3->GetYaxis()->SetTitleOffset(0.4);
  gr3->GetYaxis()->SetLabelSize(0.09);
  gr3->GetYaxis()->SetTitleSize(0.09);
  gr3->Draw("APL");
  
  c2a->cd(4);
  gr4->GetXaxis()->SetTitle("time (msec)");
  gr4->GetYaxis()->SetTitle("current (nA)");
  gr4->GetYaxis()->SetTitleOffset(1.25);
  gr4->GetXaxis()->SetTitleOffset(0.4);
  gr4->GetXaxis()->SetLabelSize(0.09);
  gr4->GetXaxis()->SetTitleSize(0.09);
  gr4->GetYaxis()->SetTitleOffset(0.4);
  gr4->GetYaxis()->SetLabelSize(0.09);
  gr4->GetYaxis()->SetTitleSize(0.09);
  gr4->Draw("APL");
  
  c2a->cd(5);
  gr5->GetXaxis()->SetTitle("time (msec)");
  gr5->GetYaxis()->SetTitle("current (nA)");
  gr5->GetYaxis()->SetTitleOffset(1.25);
  
  gr5->GetXaxis()->SetTitleOffset(0.4);
  gr5->GetXaxis()->SetLabelSize(0.09);
  gr5->GetXaxis()->SetTitleSize(0.09);
  gr5->GetYaxis()->SetTitleOffset(0.4);
  gr5->GetYaxis()->SetLabelSize(0.09);
  gr5->GetYaxis()->SetTitleSize(0.09);
  gr5->Draw("APL");
  pr5=gr5->Fit("const5","S","",d,a);
  const5->Draw("SAME");
  pr5b=gr5->Fit("const5b","S","",b,c);
  const5b->Draw("SAME");

  c2a->cd(6);
  gr6->GetXaxis()->SetTitle("time (msec)");
  gr6->GetYaxis()->SetTitle("current (nA)");  
  gr6->GetYaxis()->SetTitleOffset(1.25);
  gr6->GetXaxis()->SetTitleOffset(0.4);
  gr6->GetXaxis()->SetLabelSize(0.09);
  gr6->GetXaxis()->SetTitleSize(0.09);
  gr6->GetYaxis()->SetTitleOffset(0.4);
  gr6->GetYaxis()->SetLabelSize(0.09);
  gr6->GetYaxis()->SetTitleSize(0.09);
  gr6->Draw("APL");
  pr6=gr6->Fit("const6","S","",d,a);
  const6->Draw("SAME");
  pr6b=gr6->Fit("const6b","S","",b,c);
  const6b->Draw("SAME");

  TLegend *leg=new TLegend(0.1,0.6, 0.4,0.9);
  leg->AddEntry(gr1,"30 mbar", "P");
  leg->AddEntry(gr2,"50 mbar", "P");
  leg->AddEntry(gr3,"20 mbar", "P");
  leg->AddEntry(gr4,"70 mbar", "P");

  //leg->Draw("SAME");
  
 /* int low=170000;
  int high=175000;
  gr1->GetXaxis()->SetRangeUser(low, high);
  gr2->GetXaxis()->SetRangeUser(low, high);
  gr3->GetXaxis()->SetRangeUser(low, high);
  gr4->GetXaxis()->SetRangeUser(low, high);
  gr5->GetXaxis()->SetRangeUser(low, high);
  gr6->GetXaxis()->SetRangeUser(low, high); 
  */
  
  cout<<"  "<<pr1->Value(0)<<"\t"<<pr1b->Value(0)<<"  \t"<<pr1b->Value(0)-pr1->Value(0)<<endl;;
  cout<<"  "<<pr2->Value(0)<<"\t"<<pr2b->Value(0)<<"  \t"<<pr2b->Value(0)-pr2->Value(0)<<endl;;
  cout<<"  "<<pr5->Value(0)<<"\t"<<pr5b->Value(0)<<"  \t"<<pr5b->Value(0)-pr5->Value(0)<<endl;;
  cout<<"  "<<pr6->Value(0)<<"\t"<<pr6b->Value(0)<<"  \t"<<pr6b->Value(0)-pr6->Value(0)<<endl;;

  ofstream out;
  out.open("tempfile.txt",ios_base::app);

  out<<pr1b->Value(0)-pr1->Value(0)<<"  \t"<<pr2b->Value(0)-pr2->Value(0)<<"  \t"<<pr5b->Value(0)-pr5->Value(0)<<"  \t"<<pr6b->Value(0)-pr6->Value(0)<<endl;


}


