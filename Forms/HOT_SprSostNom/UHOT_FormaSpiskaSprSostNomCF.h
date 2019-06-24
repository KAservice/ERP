#ifndef UHOT_FormaSpiskaSprSostNomCFH                  
#define UHOT_FormaSpiskaSprSostNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaSpiskaSprSostNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaSpiskaSprSostNomCF();                                                           
   ~THOT_FormaSpiskaSprSostNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
