#ifndef UDMDocOstNomCFH                  
#define UDMDocOstNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocOstNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocOstNomCF();                                                           
   ~TDMDocOstNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
