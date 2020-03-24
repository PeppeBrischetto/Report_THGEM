void readfileAverageCompare()
{
   gStyle->SetTitleSize(0.1,"t");
  // gStyle->SetTitleOffset(14,"t");

  float I0, I1, I2, I3, I4, I5, I6, V0, V1, V2, V3, V4, V5, V6;
  int time, timeold, timeRef, timeRef2;
  int run, n, lnum=0, lnum2=0;
  char *buffer=new char[200];
  char c;
  
  ifstream in, in2;
  //in.open("Sorgente_off_on_off.txt");
  in.open("Run12.txt");
  in>>timeRef;
  
  
  // conta il numero di linee del file
  while(in>>time){
    //in>>time;
    cout<<"*"<<time<<endl;
    in>>V0>>V1>>V2>>V3>>V4>>V5>>V6;
    //cout<<V0<<"\t"<<V1<<"\t"<<V2<<"\t"<<V3<<"\t"<<V4<<"\t"<<V5<<"\t"<<V6<<endl;
    in>>I0>>I1>>I2>>I3>>I4>>I5>>I6;
    //cout<<I0<<"\t"<<I1<<"\t"<<I2<<"\t"<<I3<<"\t"<<I4<<"\t"<<I5<<"\t"<<I6<<endl;
    lnum++;
    cout<<" |"<<lnum<<endl;
  }
  cout<<"number of entries: "<<lnum<<endl;  
  in.close();
  cout<<"------------------"<<endl;
  
  
  in2.open("Run21.txt");
  in2>>timeRef2;
  // conta il numero di linee del file
  while(in2>>time){
    //in>>time;
    //cout<<"*"<<time<<endl;
    in2>>V0>>V1>>V2>>V3>>V4>>V5>>V6;
    //cout<<V0<<"\t"<<V1<<"\t"<<V2<<"\t"<<V3<<"\t"<<V4<<"\t"<<V5<<"\t"<<V6<<endl;
    in2>>I0>>I1>>I2>>I3>>I4>>I5>>I6;
    //cout<<I0<<"\t"<<I1<<"\t"<<I2<<"\t"<<I3<<"\t"<<I4<<"\t"<<I5<<"\t"<<I6<<endl;
    lnum2++;
    cout<<" |"<<lnum<<endl;
  }
  cout<<"number of entries: "<<lnum2<<endl;
  in2.close();
  

  //in.open("Sorgente_off_on_off.txt");
  in.open("Run12.txt");
 
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
    
    if(I0>3){
      cout<<"GFERgetsrgh"<<endl;
      return 1;
    }
    
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
    
    if (timeRed==timeold){
      A++;
      I0a=I0a+I0;
      I1a=I1a+I1;  
      I2a=I2a+I2;  
      I3a=I3a+I3;  
      I4a=I4a+I4;
      I5a=I5a+I5;  
      I6a=I6a+I6;    
      
    }else{
       
       I0a=I0a/A;
       I1a=I1a/A;
       I2a=I2a/A;
       I3a=I3a/A;
       I4a=I4a/A;
       I5a=I5a/A;
       I6a=I6a/A;
       
             
       if(i!=0){      
        gr1a->SetPoint(na, (time-timeRef)/1000, -I0a*1000); 
        gr2a->SetPoint(na, (time-timeRef)/1000, -I1a*1000); 
        gr3a->SetPoint(na, (time-timeRef)/1000, -I2a*1000); 
        gr4a->SetPoint(na, (time-timeRef)/1000, -I3a*1000); 
        gr5a->SetPoint(na, (time-timeRef)/1000, -I4a*1000); 
        gr6a->SetPoint(na++, (time-timeRef)/1000, -I5a*1000);     
       }
       //Resetta i parametri
       A=1;
       I0a=I0;
       I1a=I1;
       I2a=I2;
       I3a=I3;
       I4a=I4;
       I5a=I5;
       I6a=I6;

    }
    timeold=time/1000;   
  
    gr1->SetPoint(n, time-timeRef, -I0*1000); 
    gr2->SetPoint(n, time-timeRef, -I1*1000); 
    gr3->SetPoint(n, time-timeRef, -I2*1000); 
    gr4->SetPoint(n, time-timeRef, -I3*1000); 
    gr5->SetPoint(n, time-timeRef, -I4*1000); 
    gr6->SetPoint(n++, time-timeRef, -I5*1000);     
   
    //if(run>=14063 && run<=14069){gr5->SetPoint(n++, Vind, -I0); }

  } 
  DeltaT=time-timeRef;
  cout<<"DT: "<<DeltaT<<endl;
  for(i =0; i<7; i++) 
  {cout<<min[i]<<"\t"<<max[i]<<endl;}
   
   
  //SECONDO FILE
 
  in2.open("Run21.txt");
 
  TGraph *gr1b=new TGraph(0);
  TGraph *gr2b=new TGraph(0);
  TGraph *gr3b=new TGraph(0);
  TGraph *gr4b=new TGraph(0);
  TGraph *gr5b=new TGraph(0);
  TGraph *gr6b=new TGraph(0);

  n=0;na=0;
  A=1;
  I0a=I1a=I2a=I3a=I4a=I5a=I6a=0;
  timeold=0;
  
 /* for(int i=0; i<7; i++){
     max[i]=0;
     min[i]=100000;
  }*/  
  
  for(int i=0; i<lnum2; i++){
    in2>>time;
    in2>>V0>>V1>>V2>>V3>>V4>>V5>>V6;
    in2>>I0>>I1>>I2>>I3>>I4>>I5>>V6;
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
    
    if (timeRed==timeold){
      A++;
      I0a=I0a+I0;
      I1a=I1a+I1;  
      I2a=I2a+I2;  
      I3a=I3a+I3;  
      I4a=I4a+I4;
      I5a=I5a+I5;  
      I6a=I6a+I6;    
      
    }else{
       //cout<<"saluti"<<endl;
       I0a=I0a/A;
       I1a=I1a/A;
       I2a=I2a/A;
       I3a=I3a/A;
       I4a=I4a/A;
       I5a=I5a/A;
       I6a=I6a/A;
       
             
       if(i!=0){      
        gr1b->SetPoint(na, (time-timeRef2)/1000, -I0a*1000); 
        gr2b->SetPoint(na, (time-timeRef2)/1000, -I1a*1000); 
        gr3b->SetPoint(na, (time-timeRef2)/1000, -I2a*1000); 
        gr4b->SetPoint(na, (time-timeRef2)/1000, -I3a*1000); 
        gr5b->SetPoint(na, (time-timeRef2)/1000, -I4a*1000); 
        gr6b->SetPoint(na++, (time-timeRef2)/1000, -I5a*1000);     
        
        
       }
       //Resetta i parametri
       A=1;
       I0a=I0;
       I1a=I1;
       I2a=I2;
       I3a=I3;
       I4a=I4;
       I5a=I5;
       I6a=I6;

    }
    timeold=time/1000;   
     
    //if(run>=14063 && run<=14069){gr5->SetPoint(n++, Vind, -I0); }

  } 
  
  cout<<"MIN MAX"<<endl;  
  for(i =0; i<7; i++) 
  {cout<<min[i]<<"\t"<<max[i]<<endl;}
  /// FINE SECONDO FILE 
   
   
  TCanvas *c1=new TCanvas("C1");
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

  TCanvas *c1a=new TCanvas("C1a");
  TH2F *bga=new TH2F("bga","",1000,0,500,1000,-0.005,0.005);
  bga->SetStats(0);
  bga->Draw();
  gr1a->SetTitle("Anodo");
  //gr1a->GetYaxis()->SetRangeUser(min[0]*0.9,max[0]*1.1);

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

  gr1b->SetMarkerStyle(20);
  gr1b->SetMarkerSize(1);
  gr1b->SetMarkerColor(kBlue -3);
  gr1b->SetLineWidth(1);
  gr1b->SetLineColor(kBlue -3);
  gr3b->SetMarkerStyle(20);
  gr3b->SetMarkerSize(1);
  gr3b->SetMarkerColor(kGreen );
  gr3b->SetLineWidth(1);
  gr3b->SetLineColor(kGreen );
  
  gr1a->Draw("APL");
  gr1b->Draw("PL");
  //gr2a->Draw("PL");
  //gr3a->Draw("PL");
  //gr4a->Draw("PL");
  //gr5a->Draw("PL");
  //gr6a->Draw("PL");
  TCanvas *c2b=new TCanvas("C2b");
  gr3a->Draw("APL");
  gr3b->Draw("PL");
  
  
  /*bga->SetStats(0);
  TCanvas *c2a=new TCanvas("C2a");
  gr1a->SetMarkerStyle(20);
  gr1a->SetMarkerSize(1);
  gr1a->SetMarkerColor(kBlue);
  gr1a->SetLineWidth(1);
  gr1a->SetLineColor(kBlue);
  gr2a->SetMarkerStyle(20);
  gr2a->SetMarkerSize(1);
  gr2a->SetMarkerColor(kOrange);  
  gr3a->SetMarkerStyle(20);
  gr3a->SetMarkerSize(1);
  gr3a->SetMarkerColor(kGreen -3);
  gr4a->SetMarkerStyle(20);
  gr4a->SetMarkerSize(1);
  gr4a->SetMarkerColor(kCyan +1);
  gr5a->SetMarkerStyle(20);
  gr5a->SetMarkerSize(1);
  gr5a->SetMarkerColor(kGray +2);
  gr6a->SetMarkerStyle(20);
  gr6a->SetMarkerSize(1);
  gr6a->SetMarkerColor(kOrange +3);

  c2a->Divide(1,4);
  c2a->cd(1);
  //Draw->bga();
  gr1a->GetXaxis()->SetTitle("seconds");
  gr1a->GetYaxis()->SetTitle("current (nA)");
  gr1a->GetYaxis()->SetTitleOffset(1.25);
  
  gr1a->GetXaxis()->SetTitleOffset(0.4);
  gr1a->GetXaxis()->SetLabelSize(0.09);
  gr1a->GetXaxis()->SetTitleSize(0.09);
  gr1a->GetYaxis()->SetTitleOffset(0.4);
  gr1a->GetYaxis()->SetLabelSize(0.09);
  gr1a->GetYaxis()->SetTitleSize(0.09);
  
  gr1a->Draw("APL");
  c2a->cd(2);
  gr2a->GetXaxis()->SetTitle("seconds");
  gr2a->GetYaxis()->SetTitle("current (nA)");
  gr2a->GetYaxis()->SetTitleOffset(1.25);
  gr2a->GetXaxis()->SetTitleOffset(0.4);
  gr2a->GetXaxis()->SetLabelSize(0.09);
  gr2a->GetXaxis()->SetTitleSize(0.09);
  gr2a->GetYaxis()->SetTitleOffset(0.4);
  gr2a->GetYaxis()->SetLabelSize(0.09);
  gr2a->GetYaxis()->SetTitleSize(0.09);
  
  gr2a->Draw("APL");
  //gr2a->GetXaxis()->SetRangeUser(0,DeltaT);
  //gr3a->Draw("PL");
  //gr4a->Draw("PL");
  c2a->cd(3);
  gr5a->GetXaxis()->SetTitle("seconds");
  gr5a->GetYaxis()->SetTitle("current (nA)");
  gr5a->GetYaxis()->SetTitleOffset(1.25);
  
  gr5a->GetXaxis()->SetTitleOffset(0.4);
  gr5a->GetXaxis()->SetLabelSize(0.09);
  gr5a->GetXaxis()->SetTitleSize(0.09);
  gr5a->GetYaxis()->SetTitleOffset(0.4);
  gr5a->GetYaxis()->SetLabelSize(0.09);
  gr5a->GetYaxis()->SetTitleSize(0.09);
  
  gr5a->Draw("APL");
  c2a->cd(4);
  gr6a->GetXaxis()->SetTitle("seconds");
  gr6a->GetYaxis()->SetTitle("current (nA)");
  gr6a->GetYaxis()->SetTitleOffset(1.25);
  
  gr6a->GetXaxis()->SetTitleOffset(0.4);
  gr6a->GetXaxis()->SetLabelSize(0.09);
  gr6a->GetXaxis()->SetTitleSize(0.09);
  gr6a->GetYaxis()->SetTitleOffset(0.4);
  gr6a->GetYaxis()->SetLabelSize(0.09);
  gr6a->GetYaxis()->SetTitleSize(0.09);
    gr6a->Draw("APL");
  
  TLegend *leg=new TLegend(0.1,0.6, 0.4,0.9);
  leg->AddEntry(gr1,"30 mbar", "P");
  leg->AddEntry(gr2,"50 mbar", "P");
  leg->AddEntry(gr3,"20 mbar", "P");
  leg->AddEntry(gr4,"70 mbar", "P");
  */

  //leg->Draw("SAME");
}

