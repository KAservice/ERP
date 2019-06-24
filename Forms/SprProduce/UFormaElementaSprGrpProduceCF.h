#ifndef UFormaElementaSprGrpProduceCFH                  
#define UFormaElementaSprGrpProduceCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprGrpProduceCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprGrpProduceCF();                                                           
   ~TFormaElementaSprGrpProduceCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
