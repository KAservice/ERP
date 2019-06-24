#ifndef UDMSprPropertiesGrpCFH                  
#define UDMSprPropertiesGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprPropertiesGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprPropertiesGrpCF();                                                           
   ~TDMSprPropertiesGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
