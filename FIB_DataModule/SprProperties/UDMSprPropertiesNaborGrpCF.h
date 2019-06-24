#ifndef UDMSprPropertiesNaborGrpCFH                  
#define UDMSprPropertiesNaborGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprPropertiesNaborGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprPropertiesNaborGrpCF();                                                           
   ~TDMSprPropertiesNaborGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
