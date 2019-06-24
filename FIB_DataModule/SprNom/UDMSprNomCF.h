#ifndef UDMSprNomCFH                  
#define UDMSprNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprNomCF();                                                           
   ~TDMSprNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
