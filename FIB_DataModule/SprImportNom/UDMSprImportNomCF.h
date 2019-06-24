#ifndef UDMSprImportNomCFH                  
#define UDMSprImportNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprImportNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprImportNomCF();                                                           
   ~TDMSprImportNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
