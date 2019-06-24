#ifndef UDMSprSezKFSProdCFH                  
#define UDMSprSezKFSProdCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprSezKFSProdCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprSezKFSProdCF();                                                           
   ~TDMSprSezKFSProdCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
