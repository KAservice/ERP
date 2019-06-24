#include "vcl.h"
#pragma hdrstop  
#include "UHLP_DMSprNaborInfBlockGrpCF.h"   
#include "UHLP_DMSprNaborInfBlockGrpImpl.h"  
#include "IHLP_DMSprNaborInfBlockGrp.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THLP_DMSprNaborInfBlockGrpCF::THLP_DMSprNaborInfBlockGrpCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THLP_DMSprNaborInfBlockGrpCF::~THLP_DMSprNaborInfBlockGrpCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockGrpCF::kanQueryInterface(REFIID id_interface, void**ppv)  
{    
int result=0;  
if (id_interface==IID_IkanUnknown) 
	{  
	*ppv=static_cast<IkanUnknown*> (this);  
	result=-1;  
	} 
else if (id_interface==IID_IkanClassFactory) 
	{  
	*ppv=static_cast<IkanClassFactory*> (this); 
	result=-1; 
	} 
else  
	{   
	*ppv=NULL;  
	result=0;  
	return result;  
	} 
kanAddRef();  
return result;  
}   
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockGrpCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockGrpCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THLP_DMSprNaborInfBlockGrpCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THLP_DMSprNaborInfBlockGrpImpl * ob=new THLP_DMSprNaborInfBlockGrpImpl();  
		if (ob->kanQueryInterface(id_interface, ppv)==-1)   
			{       
			result=-1;  
			}    
		else     
			{           
			delete ob;   
			result=0;   
			}      
return result;  
}       
//---------------------------------------------------------------
