#ifndef UFormaSpiskaSprVidNomCFH                  
#define UFormaSpiskaSprVidNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprVidNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprVidNomCF();                                                           
   ~TFormaSpiskaSprVidNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
