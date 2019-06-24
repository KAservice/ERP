#ifndef UFormaSpiskaSprVidKlientCFH                  
#define UFormaSpiskaSprVidKlientCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprVidKlientCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprVidKlientCF();                                                           
   ~TFormaSpiskaSprVidKlientCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
