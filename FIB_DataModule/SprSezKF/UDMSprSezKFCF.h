#ifndef UDMSprSezKFCFH                  
#define UDMSprSezKFCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprSezKFCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprSezKFCF();                                                           
   ~TDMSprSezKFCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
