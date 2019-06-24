#ifndef UDMSprGrpProduceCFH                  
#define UDMSprGrpProduceCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprGrpProduceCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprGrpProduceCF();                                                           
   ~TDMSprGrpProduceCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
