#ifndef UDMSprGrpBusinessOperCFH                  
#define UDMSprGrpBusinessOperCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprGrpBusinessOperCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprGrpBusinessOperCF();                                                           
   ~TDMSprGrpBusinessOperCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
