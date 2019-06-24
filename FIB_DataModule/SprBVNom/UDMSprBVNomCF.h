#ifndef UDMSprBVNomCFH                  
#define UDMSprBVNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprBVNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprBVNomCF();                                                           
   ~TDMSprBVNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
