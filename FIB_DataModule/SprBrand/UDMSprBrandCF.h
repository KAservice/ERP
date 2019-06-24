#ifndef UDMSprBrandCFH                  
#define UDMSprBrandCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprBrandCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprBrandCF();                                                           
   ~TDMSprBrandCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
