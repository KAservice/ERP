#ifndef UFormaSpiskaSprDocKlientCFH                  
#define UFormaSpiskaSprDocKlientCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprDocKlientCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprDocKlientCF();                                                           
   ~TFormaSpiskaSprDocKlientCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
