#ifndef UFormaSpiskaSprTypeNomCFH                  
#define UFormaSpiskaSprTypeNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprTypeNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprTypeNomCF();                                                           
   ~TFormaSpiskaSprTypeNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
