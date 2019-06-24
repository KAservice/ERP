#ifndef UHOT_FormaSpiskaSprNFCFH                  
#define UHOT_FormaSpiskaSprNFCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaSpiskaSprNFCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaSpiskaSprNFCF();                                                           
   ~THOT_FormaSpiskaSprNFCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
