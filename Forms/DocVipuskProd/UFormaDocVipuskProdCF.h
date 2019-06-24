#ifndef UFormaDocVipuskProdCFH                  
#define UFormaDocVipuskProdCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocVipuskProdCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocVipuskProdCF();                                                           
   ~TFormaDocVipuskProdCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
