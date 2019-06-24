#ifndef UFormaSpiskaSprSellerCFH                  
#define UFormaSpiskaSprSellerCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprSellerCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprSellerCF();                                                           
   ~TFormaSpiskaSprSellerCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
