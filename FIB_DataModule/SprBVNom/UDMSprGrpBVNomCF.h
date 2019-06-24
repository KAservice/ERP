#ifndef UDMSprGrpBVNomCFH                  
#define UDMSprGrpBVNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprGrpBVNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprGrpBVNomCF();                                                           
   ~TDMSprGrpBVNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
